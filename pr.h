#ifndef queue_h
#define queue_h

#include<stdlib.h>
#include<stdio.h>

struct Node 
{
    int data;
    struct Node *next;
} *front=0, *rear=0;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(!t)
    printf("Queue is full\n");
    else
    {
        t->data = x;
        t->next = 0;
        if(!front)
        front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;
    if(!front)
    printf("Queue is empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return (front == 0);
}

#endif 
