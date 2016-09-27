//
// Created by cvelez on 9/26/2016.
//

#include "stack.h"
#include "stdlib.h"
#include "stdio.h"

void stack_create(stack_t** stack, unsigned int initialCapacity)
{
	*stack = (stack_t*) malloc(sizeof(stack_t));
	stack_t* _stack = *stack;

	_stack->capacity = initialCapacity;
	_stack->count = 0;
	_stack->errno = 0;
	_stack->stack = (int*) malloc(sizeof(int) * _stack->capacity);
}

void stack_push(stack_t* stack, int key)
{
	if (stack->capacity == stack->count) {
		stack->errno = STACK_OVERFLOW_ERROR;
		return;
	}

	stack->stack[stack->count++] = key;
	stack->errno = STACK_SUCCESS;
}

int stack_pop(stack_t* stack)
{
	if (stack->count == 0) {
		stack->errno = STACK_UNDERFLOW_ERROR;
		return NULL;
	}

	int popped = stack->stack[--stack->count];
	return popped;
}

int stack_peek(stack_t* stack)
{
	if (stack->count == 0) {
		stack->errno = STACK_UNDERFLOW_ERROR;
		return NULL;
	}

	return stack->stack[stack->count];
}

void stack_print(stack_t* stack)
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