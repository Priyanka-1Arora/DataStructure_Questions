#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct {
    int top;
    int arr[100];
} MyQueue;
MyQueue e1;

MyQueue* myQueueCreate() {
    e1.top=-1;
    return &e1;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->top+=1;
    obj->arr[obj->top]=x;
}

int myQueuePop(MyQueue* obj) {
    int val=obj->arr[0];
    for(int i=1;i<=obj->top;i++){
        obj->arr[i-1]=obj->arr[i];
    }
    obj->top-=1;
    return val;
}

int myQueuePeek(MyQueue* obj) {
    return obj->arr[0];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top==-1?true:false;
}

void myQueueFree(MyQueue* obj) {
    obj->top=-1;
}

int main(){}