#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdbool.h>
bool empty();
unsigned int size();
int front();
void push(int data);
int pop(void);

#endif
