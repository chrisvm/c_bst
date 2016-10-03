//
// Created by cvelez on 9/26/2016.
//

#include "stack.h"
#include "stdlib.h"
#include "stdio.h"

void stack_create(struct stack_t** stack, unsigned int initialCapacity)
{
	*stack = (struct stack_t*) malloc(sizeof(struct stack_t));
	struct stack_t* _stack = *stack;

	_stack->capacity = initialCapacity;
	_stack->count = 0;
	_stack->errno = 0;
	_stack->stack = (int*) malloc(sizeof(int) * _stack->capacity);
}

void stack_push(struct stack_t* stack, int key)
{
	if (stack->capacity == stack->count) {
		stack->errno = STACK_OVERFLOW_ERROR;
		return;
	}

	stack->stack[stack->count++] = key;
	stack->errno = STACK_SUCCESS;
}

int stack_pop(struct stack_t* stack)
{
	if (stack->count <= 0) {
		stack->errno = STACK_UNDERFLOW_ERROR;
		return 0;
	}

	int popped = stack->stack[stack->count--];
	stack->errno = STACK_SUCCESS;
	return popped;
}

int stack_peek(struct stack_t* stack)
{
	if (stack->count == 0) {
		stack->errno = STACK_UNDERFLOW_ERROR;
		return 0;
	}

	stack->errno = STACK_SUCCESS;
	return stack->stack[stack->count];
}

void stack_print(struct stack_t* stack)
{
	if (stack->count == 0) {
		printf("[]");
		return;
	}

	printf("[%i", stack->stack[0]);

	int index;
	for (index = 1; index < stack->count; ++index) {
		printf(",%i", stack->stack[index]);
	}

	printf("]");
}
