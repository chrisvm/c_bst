//
// Created by cvelez on 8/24/2016.
//
#include "bst.h"
#include "malloc.h"

void bst_set_null_unused(struct bst_tree_t *tree) {
	// all used in tree, no node unused to set null
	if (tree->nodeCount == tree->capacity) {
		return;
	}

	for (int index = tree->nodeCount; index < tree->capacity; ++index) {
		tree->nodes[index].isNull = 1;
	}
}

int bst_create_tree(struct bst_tree_t* tree) {
    tree->nodeCount = 0;
    tree->capacity = 2;
    tree->nodes = malloc(sizeof(struct bst_tree_t) * tree->capacity);
    bst_set_null_unused(tree);
    return 1;
}

int bst_set_capacity(struct bst_tree_t* tree, int capacity) {
    // if capacity less than zerp, return error (0)
    if (capacity < 0) {
        return 0;
    }

    // if capacity equal or more to actual capacity, return with no error (1)
    if (tree->capacity >= capacity) {
        return 1;
    }

    // keep reference to old nodes (to copy)
    struct bst_node_t* temp = tree->nodes;

    // create new memory space with size requested
    tree->nodes = realloc(tree->nodes, sizeof(struct bst_node_t) * capacity);

    // set null to unused
	bst_set_null_unused(tree);
}