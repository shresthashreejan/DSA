#include "data_structures/stack.h"

int arr[MAX];
int top = -1;

void push(int n)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    arr[++top] = n;
}

int pop(void)
{
    if (top < 0)
    {
        printf("Stack underflow\n");
        return -1;
    }

    int val = arr[top];
    arr[top] = 0;
    --top;

    return val;
}

void printStack(void)
{
    printf("Stack: ");
    for (int i = 0; i < MAX; ++i) printf("%d ", arr[i]);
}

void Stack(void)
{
    printf("STACK\n");
    push(1);
    push(2);
    push(3);
    printf("Popped value: %d\n", pop());
    printStack();
    printf("\n");
}