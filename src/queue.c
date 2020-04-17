/**
 * @file
 * @brief FIFO Queue
 *
 * This file contains the source code for FIFO Queue
 */

#include <stdliib.h>
#include <pthread.h>
#include "queue/queue.h"

#define ERROR -1

static pthread_mutex_t queue_mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node *queueFront = NULL, *queueRear = NULL;
unsigned int queueCount = 0;

/*Checks whether the Queue is empty*/
bool empty() { return (queueFront == NULL); }


/*Returns the number of entries in the Queue*/
unsigned int size() { return queueCount; }

/*Access the first element in the Queue*/
int front()
{
    if(!empty()) {
        return queueFront->data;    
    } else {
        printf("No elements in Queue\n");
        return ERROR;
    }
}

/*Access the last element in the Queue*/
int back()
{
    if(!empty()) {
        return queueRear->data;
    } else {
        printf("No elements in Queue\n");
        return ERROR;
    }
}

/*Insert an element to the Queue*/
void push(int data) {
    pthread_mutex_lock(&queue_mutex);
    Node *newEntry = (Node *)malloc(sizeof(Node));
    if (NULL != newEntry) {
        newEntry->data = data;
        newEntry->next = NULL;
        if (NULL == queueFront) {
            queueFront = newEntry;
            queueRear = newEntry;
        } else {
            queueRear->next = newEntry;
            queueRear = newEntry;
        }
        queueCount++;
    } else {
        printf("No space left in the device\n");
    }
    pthread_mutex_unlock(&queue_mutex);
}

/*Remove the next element from the Queue*/
void pop() {
    pthread_mutex_lock(&queue_mutex);
    if (empty()) {
        printf("Stack is empty\n");
        return;
    }

    Node *temp = queueFront;
    queueFront = queueFront->next;
    queueCount--;
    free(temp);
    pthread_mutex_unlock(&queue_mutex);
}
