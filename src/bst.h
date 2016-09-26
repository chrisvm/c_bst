//
// Created by cvelez on 8/24/2016.
//

#ifndef BST_BST_H
#define BST_BST_H

// node structure
struct bst_node_t
{
    int isNull;
    int value;
    int leftOffset;
    int rightOffset;
};

// bst structure
struct bst_tree_t
{
    int nodeCount;
    unsigned int capacity;
    struct bst_node_t* nodes;
};

// creates an instance of a tree
int bst_create_tree(struct bst_tree_t** tree);

// bumps the capacity of a tree in power of two increments
int bst_bump_capacity(struct bst_tree_t** _tree);

// copies a node from tree with an index to another tree
void bst_copy_node(struct bst_node_t* tree1, unsigned int index1,
	struct bst_node_t* tree2, unsigned int index2);

// sets the unused nodes to null; usefull when expanding the tree capacity
void bst_set_null_unused(struct bst_tree_t *pTree);

// print the contents of a tree
void bst_debug_print(struct bst_tree_t* tree);

// add a number to the tree
void bst_add_key(struct bst_tree_t* tree, int key);

// finds the would-be parent for a key
struct bst_node_t* bst_parent_for_key(struct bst_tree_t* tree, int key);

// check if node is null
unsigned int node_is_leaf(struct bst_node_t *node);

// check if has key
unsigned int tree_has_key(struct bst_tree_t* tree, int key);

#endif //BST_BST_H
