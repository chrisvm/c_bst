//
// Created by cvelez on 10/2/2016.
//

#include "queue.h"
#include "stdlib.h"
#include "stdio.h"

/**
struct queue_t
{
	unsigned int count;
	unsigned int capacity;
	int* queue;
	unsigned short errno;
};
*/
void queue_create(struct queue_t** queue)
{
	// create queue struct
	*queue = (struct queue_t*) malloc(sizeof(struct queue_t));
	struct queue_t* _queue = *queue;

	// init the queue
	_queue->count = 0;
	_queue->errno = 0;
	_queue->queue = NULL;
}

void queue_enqueue(struct queue_t* queue, int key)
{
	// create node from key
	struct queue_node_t* newNode = (struct queue_node_t*) malloc(sizeof(struct queue_node_t));
	newNode->next = NULL;
	newNode->key = key;

	// if queue.queue is null, just add
	if (queue->queue == NULL) {
		// set queue.queue to point to node
		queue->queue = newNode;
	} else {
		// get to last node in list
		struct queue_node_t* lastNode = queue->queue;
		while (lastNode->next != NULL) {
			lastNode = lastNode->next;
		}

		// add to end
		lastNode->next = newNode;
	}

	// bump queue.count
	queue->count += 1;

	// set error to success
	queue->errno = QUEUE_SUCCESS;
}

int queue_dequeue(struct queue_t* queue)
{
	// if queue empty, return error
	if (queue->queue == NULL) {
		queue->errno = QUEUE_UNDERFLOW_ERROR;
		return 0;
	}

	// hold temp node

}

int queue_peek(struct queue_t* queue)
{

}