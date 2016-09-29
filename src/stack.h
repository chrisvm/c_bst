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

void stack_create(struct stack_t** stack, unsigned int initialCapacity);
void stack_push(struct stack_t* stack, int key);
int stack_pop(struct stack_t* stack);
int stack_peek(struct stack_t* stack);
void stack_print(struct stack_t* stack);

#endif //BST_STACK_H
