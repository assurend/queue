#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

static pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node *queueFront = NULL, *queueRear = NULL;
unsigned int queueCount = 0;

bool empty()
{
    return (queueFront == NULL);
}

unsigned int size()
{
    return queueCount;
}

int front()
{
    if(!empty())
    {
        return queueFront->data;    
    }
    else
    {
        printf("No elements in Queue\n");
        return -1;
    }
}

int back()
{
    if(!empty())
    {
        return queueRear->data;
    }
    else
    {
        printf("No elements in Queue\n");
        return -1;
    }
}
void push(int data)
{
    pthread_mutex_lock(&queue_mutex);
    Node* newEntry =  (Node*)malloc(sizeof(Node));
    if(NULL != newEntry)
    {
        newEntry->data = data;
        newEntry->next = NULL;
        if(NULL == queueFront)
        {
            queueFront = newEntry;
            queueRear = newEntry;
        }
        else if(NULL == queueRear)
        {
            queueRear = newEntry;
        }
        else
        {
            Node* temp = queueRear;
            queueRear = newEntry;
            temp->next = queueRear;
            
        }
        queueCount++;
    }
    else
    {
        printf("No space left in Queue");
    }
    pthread_mutex_unlock(&queue_mutex);
}

int pop(void)
{
    pthread_mutex_lock(&queue_mutex);
    if(empty())
    {
        printf("Queue is empty\n");
        return -1;
    }
        
    Node* temp = queueFront;
    int data = temp->data;
    queueFront = queueFront->next;
    free(temp);
    queueCount--;

    pthread_mutex_unlock(&queue_mutex);
    return data;
}
