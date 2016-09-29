//
// Created by cvelez on 8/24/2016.
//
#include "bst.h"
#include "stack.h"
#include "stdio.h"
#include "malloc.h"

void bst_set_null_unused(struct bst_tree_t *tree)
{
	// all used in tree, no node unused to set null
	if (tree->nodeCount == tree->capacity) {
		return;
	}

	int index;
	for (index = tree->nodeCount; index < tree->capacity; ++index) {
		tree->nodes[index].isNull = 1;
		tree->nodes[index].leftOffset = tree->nodes[index].rightOffset = 0;
	}
}

int bst_create_tree(struct bst_tree_t** tree)
{
	tree[0] = malloc(sizeof(struct bst_tree_t));

	struct bst_tree_t* _tree = *tree;
    _tree->nodeCount = 0;
    _tree->capacity = 3;
    _tree->nodes = calloc(_tree->capacity, sizeof(struct bst_tree_t));
    bst_set_null_unused(_tree);
    return 1;
}

void bst_copy_node(struct bst_node_t* tree1, unsigned int index1,
	struct bst_node_t* tree2, unsigned int index2)
{
	tree2[index2].isNull = tree1[index1].isNull;
	tree2[index2].value = tree1[index1].value;
	tree2[index2].leftOffset = tree1[index1].leftOffset;
	tree2[index2].rightOffset = tree1[index1].rightOffset;
}

int bst_bump_capacity(struct bst_tree_t** tree)
{
	struct bst_tree_t* _tree = *(tree);

    // keep reference to old nodes (to copy)
    struct bst_node_t* temp = _tree->nodes;

	// keep old capacity, to iterate old array later
	unsigned int oldCapacity = _tree->capacity;

	// bump old capacity
	_tree->capacity *= 2;

    // create new memory space with size requested
    _tree->nodes = calloc(_tree->capacity, sizeof(struct bst_node_t));

	// copy old values
	int index;
	for (index = 0; index < oldCapacity; ++index) {
		bst_copy_node(temp, index, _tree->nodes, index);
	}

    // set null to unused
	bst_set_null_unused(_tree);

	// free old array
	free(temp);
}

void bst_debug_print(struct bst_tree_t* tree)
{
	int index;
	struct bst_node_t node;

	printf("Node Offset | isNull      | Value       | Left        | Right      \n");
	printf("-------------------------------------------------------------------\n");
	for (index = 0; index < tree->capacity; ++index) {
		node = tree->nodes[index];
		printf("%11i | %11i | %11i | %11i | %11i \n", index, node.isNull, node.value, node.leftOffset, node.rightOffset);
	}
}

void bst_add_key(struct bst_tree_t* tree, int key)
{
	// if already in tree, dont add
	if (bst_has_key(tree, key)) {
		return;
	}

	// add to the last open space (we guarantee is always open)
	int newNodeIndex = tree->nodeCount++;
	tree->nodes[newNodeIndex].isNull = 0;
	tree->nodes[newNodeIndex].value = key;

	// if first node, return
	if (newNodeIndex == 0) {
		return;
	}

	// start in the root node (index == 0)
	struct bst_node_t* currentNode = &(tree->nodes[0]);

	while (1) {
		// check direction
		if (key < currentNode->value) {
			if (currentNode->leftOffset == 0) {
				currentNode->leftOffset = newNodeIndex + 1;
				break;
			}
			currentNode = &(tree->nodes[currentNode->leftOffset - 1]);
		} else {
			if (currentNode->rightOffset == 0) {
				currentNode->rightOffset = newNodeIndex + 1;
				break;
			}
			currentNode = &(tree->nodes[currentNode->rightOffset - 1]);
		}
	}

	// check if we filled the capacity
	if (tree->nodeCount == tree->capacity) {
		bst_bump_capacity(&tree);
	}
}

unsigned int bst_has_key(struct bst_tree_t* tree, int key)
{
	struct bst_node_t* currentNode = &tree->nodes[0];
	while (1) {
		// if found, return
		if (currentNode->value == key) {
			return 1;
		}

		// did not found the key
		if (currentNode->isNull) {
			return 0;
		}

		if (key < currentNode->value) {
			if (currentNode->leftOffset == 0) {
				return 0;
			}
			currentNode = &tree->nodes[currentNode->leftOffset - 1];
		} else {
			if (currentNode->rightOffset == 0) {
				return 0;
			}
			currentNode = &tree->nodes[currentNode->rightOffset - 1];
		}
	}
}

// todo: finish this method. use stack to get the height of the tree
void bst_pretty_print(struct bst_tree_t* tree)
{
	unsigned int maxHeight = 0, currentIndex = 0;

	// create stack
	struct stack_t* stack;
	stack_create(&stack, tree->nodeCount);

	// find height of tree (using stack)
}

unsigned int node_is_leaf(struct bst_node_t *node)
{
	return (node->rightOffset == 0 && node->leftOffset == 0);
}
