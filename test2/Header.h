#pragma once
#pragma once
#ifndef __LITE_QUEUE_h__
#define __LITE_QUEUE_h__

#include <stdbool.h>

typedef struct _stack
{
	char *data;
	int size;
	int capacity;
}Stack, *StackPtr;

typedef void(*LITE_FUNC)(char);


void push_stack(StackPtr* ptr, const char data);
char pop_stack(StackPtr* ptr);

void satack_foreach(StackPtr, LITE_FUNC);

bool stack_empty(StackPtr);

#endif

