//
// Created by cvelez on 8/24/2016.
//

#ifndef BST_BST_H
#define BST_BST_H

struct bst_node_t {
    int isNull;
    int value;
    int leftOffset;
    int rightOffset;
};

struct bst_tree_t {
    int nodeCount;
    int capacity;
    struct bst_node_t* nodes;
};

int bst_create_tree(struct bst_tree_t* tree);
int bst_set_capacity(struct bst_tree_t* tree, int capacity);
void bst_set_null_unused(struct bst_tree_t *pTree);
#endif //BST_BST_H