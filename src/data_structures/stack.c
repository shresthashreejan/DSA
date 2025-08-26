#include "data_structures/stack.h"

static int arr[MAX];
static int top = -1;

void Push(int n)
{
    if (top >= MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }

    arr[++top] = n;
}

int Pop(void)
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

void PrintStack(void)
{
    printf("Stack: ");
    for (int i = 0; i < MAX; ++i) printf("%d ", arr[i]);
}

void Stack(void)
{
    printf("STACK\n");
    Push(1);
    Push(2);
    Push(3);
    printf("Popped value: %d\n", Pop());
    PrintStack();
    printf("\n\n");
}