//
// Created by cvelez on 8/24/2016.
//
#include "bst.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void main(int argc, char** argv) {
    // create a tree
	struct bst_tree_t* tree;
	bst_create_tree(&tree);

	// print the tree
	bst_debug_print(tree);

	// seed the rand function
	time_t t;
	srand((unsigned) time(&t));

	// add 10 randome elements from range [0, 9]
	int times;
	for (times = 0; times < 10; ++times) {
		int toAdd = rand() % 10;
		printf("added %i\n", toAdd);
		bst_add_key(tree, toAdd);
	}

	srand((unsigned) time(&t));

	// check ten random numbers
	for (times = 0; times < 10; ++times) {
		// get random number to check
		int toCheck = rand() % 20;
		// check what string to print
		char *toPrint = (tree_has_key(tree, toCheck)) ? "true" : "false";
		// log the result
		printf("tree has %7i: %5s\n", toCheck, toPrint);
	}

	bst_debug_print(tree);
    exit(0);
}
