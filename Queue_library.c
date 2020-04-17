#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        printf("No elements in Queue");
        return -1;
    }
}

void push(int data)
{
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
}

int pop(void)
{
    if(empty())
    {
        printf("Stack is empty");
        return -1;
    }
        
    Node* temp = queueFront;
    int a = temp-> data;
    queueFront = queueFront->next;
    free(temp);
    queueCount--;
    return a;
}
