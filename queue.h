#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define LEN 50
#define MAX 255

struct queue {
	char arr[LEN][MAX];
	int size;
	int rear;
	int front;
};

typedef struct queue queue;

queue* create_queue()
{
	queue* me = (queue*)malloc(sizeof(queue));
	if (me) {
		me->rear = -1;
		me->front = -1;
		me->size = 0;
		return me;
	}
}
bool isEmpty(queue* me) {
	if (me) {
		if (me->front == -1 && me->rear == -1) return true;
		else if (me->front > me->rear) return true;
		else return false;
	}
}
void enqueue(queue* me, char* value) {
	// some code
	if (isEmpty(me)) me->front++;
	me->rear++;
	me->size++;
	strncpy(me->arr[me->rear], value, MAX);
}

char* dequeue(queue* me) {
	if (isEmpty(me)) return NULL;
	//me->size--;
	return me->arr[me->front++];
}



void print_queue(queue* me) {
	printf("[");
	for (int i = me->front; i < me->size - 1; i++) {
		printf("%s, ", me->arr[i]);
	}
	printf("%s]\n", me->arr[me->size - 1]);
}
