#ifndef queue_h
#define queue_h

#include<stdlib.h>
#include<stdio.h>

struct node 
{
    int data;
    struct node *next;
}*front=NULL, *rear=NULL;

void enqueue(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    
    if(!temp)
    {
        printf("Queue is full\n");
        return;
    }

    temp->data=x;
    temp->next=NULL;
    if(!front)
    front = rear = temp;
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

int isEmpty()
{
    return (front == NULL);
}

int dequeue()
{
    int x=-1;
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(isEmpty())
    printf("Queue is empty\n");
    else
    {
        x = front->data;
        temp = front;
        front = front->next;
        free(temp);
    }
    return x;
}


#endif 
