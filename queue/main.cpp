#include <iostream>
#include <stdio.h>

struct Queue
{
	int front, rear, size; // front : first queue | rear : last queue | size : size queue
	unsigned cap;	// capacity queue
	int* arr;		// array queue
};

struct Queue* createQueue(unsigned cap)
{
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue*));
	queue->cap = cap;
	queue->front = queue->size = 0; // initialized size and first queue 
	queue->rear = cap - 1;			// ??
	queue->arr = (int*)malloc(queue->cap * sizeof(int)); // when it's free
	return queue;
}

int isFull(struct Queue* queue)
{
	return (queue->size == queue->cap);
}

int isEmpty(struct Queue* queue)
{
	return (queue->size == 0);
}

void enqueue(Queue* queue, int item)
{
	if (isFull(queue)) // check queue is full
	{
		printf("Full queue !!");
		return;
	}
	queue->rear = (queue->rear + 1) % queue->cap; // ??
	queue->arr[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("enqueue with item %d \n", item);
}

int dequeue(Queue* queue)
{
	if (isEmpty(queue))
	{
		return -1;
	}
	int item = queue->arr[queue->front];
	queue->front = (queue->front + 1) % queue->cap;
	queue->size = queue->size - 1;
	return item;
}

int get_front(struct Queue* queue)
{
	if (isEmpty(queue))
		return 0;
	return queue->arr[queue->front];
}

int get_rear(struct Queue* queue)
{
	if (isEmpty(queue))
		return 0;
	return queue->arr[queue->rear];
}

int main()
{
	Queue* queue = createQueue(10);
	printf("start\n");

	// add queue
	enqueue(queue, 2);
	enqueue(queue, 3);
	enqueue(queue, 4);

	printf("get front = %d \n", get_front(queue));
	printf("get rear = %d \n", get_rear(queue));

	getchar();
	return 0;
}