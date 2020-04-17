/**
 * @file
 * @brief FIFO Queue header file
 *
 * This is the header file for FIFO Queue
 */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>

bool empty();
unsigned int size();
int front();
int back();
void push(int data);
void pop();

#endif
