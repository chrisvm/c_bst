//
// Created by cvelez on 10/2/2016.
//

#ifndef BST_QUEUE_H
#define BST_QUEUE_H

#define QUEUE_SUCCESS 0;
#define QUEUE_OVERFLOW_ERROR 1
#define QUEUE_UNDERFLOW_ERROR 2;

// queue struct definition
struct queue_t
{
	unsigned int count;
	struct queue_node_t* queue;
	unsigned short errno;
};

struct queue_node_t
{
	struct queue_node_t* next;
	int key;
};

void queue_create(struct queue_t** queue);
void queue_enqueue(struct queue_t* queue, int key);
int queue_dequeue(struct queue_t* queue);
int queue_peek(struct queue_t* queue);

#endif //BST_QUEUE_H
