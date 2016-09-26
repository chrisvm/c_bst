//
// Created by cvelez on 8/24/2016.
//
#include "bst.h"
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
	if (!*tree) {
		*tree = malloc(sizeof(struct bst_tree_t));
	}

	struct bst_tree_t* _tree = *tree;
    _tree->nodeCount = 0;
    _tree->capacity = 3;
    _tree->nodes = malloc(sizeof(struct bst_tree_t) * _tree->capacity);
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

int bst_bump_capacity(struct bst_tree_t* tree)
{
    // keep reference to old nodes (to copy)
    struct bst_node_t* temp = tree->nodes;

	// keep old capacity, to iterate old array later
	unsigned int oldCapacity = tree->capacity;

	// bump old capacity
	tree->capacity *= 2;

    // create new memory space with size requested
	unsigned int newSize = sizeof(struct bst_node_t) * tree->capacity;
    tree->nodes = malloc(newSize);

	// copy old values
	int index;
	for (index = 0; index < oldCapacity; ++index) {
		bst_copy_node(temp, index, tree->nodes, index);
	}

    // set null to unused
	bst_set_null_unused(tree);

	// free old array
	free(temp);
}

void bst_debug_print(struct bst_tree_t* tree)
{
	int index;
	struct bst_node_t node;

	printf("Node Offset | isNull      | Value      \n");
	for (index = 0; index < tree->capacity; ++index) {
		node = tree->nodes[index];
		printf("%i | %i | %i \n", index, node.isNull, node.value);
	}
}

// todo: finish this method
void bst_add_key(struct bst_tree_t* tree, int key)
{
	// add to the last open space (we guarantee is always open)
	int newNodeIndex = tree->nodeCount++;
	tree->nodes[newNodeIndex].isNull = 0;
	tree->nodes[newNodeIndex].value = key;

	// if first node, return
	if (newNodeIndex == 0) {
		return;
	}

	// look where to add the key
	unsigned short found = 0;

	// start in the root node (index == 0)
	struct bst_node_t* currentNode = &(tree->nodes[0]), *tNode = NULL;

	while (!found) {

		// check if leaf node
		if (node_is_leaf(currentNode)) {
			if (key < currentNode->value) {
				currentNode->leftOffset = newNodeIndex + 1;
			} else {
				currentNode->rightOffset = newNodeIndex + 1;
			}
			break;
		}

		// save current node
		tNode = currentNode;

		unsigned int toAddIndex;
		if (key < currentNode->value) {
			toAddIndex = currentNode->leftOffset - 1;
		} else {
			toAddIndex = currentNode->rightOffset - 1;
		}

		currentNode = &(tree->nodes[toAddIndex]);

		// if null, found place to add
		if (currentNode->isNull) {

		}
	}

	// check if we filled the capacity
	if (tree->nodeCount == tree->capacity) {
		bst_bump_capacity(tree);
	}
}

unsigned int node_is_leaf(struct bst_node_t *node)
{
	return (node->rightOffset == 0 && node->leftOffset == 0);
}