#include <assert.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct {
    int arr[1000];
    int front;
    int rear;
    int maxSize;
} MyCircularQueue;
MyCircularQueue e1;

MyCircularQueue* myCircularQueueCreate(int k) {
    e1.front=-1;
    e1.rear=-1;
    e1.maxSize=k;
    return &e1;
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return((obj->front==-1))?true:false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj->rear+1)%obj->maxSize==obj->front)?true:false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }

    if (myCircularQueueIsEmpty(obj)) {
        obj->front = 0;
    }

    obj->rear = (obj->rear + 1) % obj->maxSize;
    obj->arr[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }

    if (obj->front == obj->rear) {
        obj->front = -1;
        obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->maxSize;
    }

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return obj->front==-1?-1:obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return obj->rear==-1?-1:obj->arr[obj->rear];
}


void myCircularQueueFree(MyCircularQueue* obj) {
    obj->front=-1;
    obj->rear=-1;
}


int main(){}