#include "Header.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const int ALLOC_STEP = 100;

void push_stack(StackPtr* ptr, const char data)
{
	assert(ptr != 0);
	if (*ptr == 0)
	{
		*ptr = (StackPtr)calloc(1, sizeof(Stack));
	}
	if ((*ptr)->size + 1 > (*ptr)->capacity)
	{
		(*ptr)->data = (char*)realloc((*ptr)->data, (*ptr)->capacity + ALLOC_STEP);
		(*ptr)->capacity = (*ptr)->capacity + ALLOC_STEP;
	}
	(*ptr)->data[(*ptr)->size] = data;
	(*ptr)->size += 1;
}
char pop_stack(StackPtr* ptr)
{
	assert(ptr != 0 && (*ptr) != 0 && (*ptr)->size != 0);

	int account = (*ptr)->size - 1;
	char ret = (*ptr)->data[account];
	(*ptr)->data[account] = '\0';
	(*ptr)->size -= 1;
	return ret;
}
bool stack_empty(StackPtr stackPtr)
{
	assert(stackPtr != 0);
	return stackPtr->size == 0;
}
void stack_foreach(StackPtr stack, LITE_FUNC func)
{
	assert(stack);
	for (int i = 0; i < stack->size; i++)
	{
		func(stack->data[i]);
	}
}
void instructions(void);

void printElement(char data)
{
	printf("%c ", data);
}
int main()
{
	StackPtr pStack = 0;

	char item;

	instructions();
	printf("? ");
	int choice;
	scanf("%d", &choice);

	while (choice != 4)
	{

		switch (choice)
		{

		case 1:
		{
			printf("Enter a character: ");
			scanf("\n%c", &item);
			push_stack(&pStack, item);
		}
		break;
		case 2:
		{
			if (!stack_empty(pStack))
			{
				item = pop_stack(&pStack);
				printf("\'%c\' has been destack.\n", item);
			}

		}
		break;

		case 3:
		{
			printf("Stack elements:\n");
			stack_foreach(pStack, printElement);
			printf("\n");
		}
		break;

		default:
			printf("Invalid choice.\n\n");
			instructions();
			break;
		}

		printf("? ");
		scanf("%d", &choice);
	}

	printf("End of run.\n");
	return 0;
}

void instructions(void)
{
	printf("Enter your choice:\n"
		"   1 to add an item to the stack\n"
		"   2 to remove an item from the stack\n"
		"   3 show all elements in the stack\n"
		"   4 to end\n");
}