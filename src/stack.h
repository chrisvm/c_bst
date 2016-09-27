//
// Created by cvelez on 9/26/2016.
//

#ifndef BST_STACK_H
#define BST_STACK_H

#define STACK_SUCCESS 0;
#define STACK_OVERFLOW_ERROR 1
#define STACK_UNDERFLOW_ERROR 2;

struct stack_t
{
	unsigned int count;
	unsigned int capacity;
	int* stack;
	unsigned short errno;
};

void stack_create(stack_t** stack, unsigned int initialCapacity);
void stack_push(stack_t* stack, int key);
int stack_pop(stack_t* stack);
int stack_peek(stack_t* stack);
void stack_print(stack_t* stack);

#endif //BST_STACK_H
