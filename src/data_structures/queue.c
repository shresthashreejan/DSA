#include "data_structures/queue.h"

static int arr[MAX];
static int head = 0;
static int tail = -1;

void Enqueue(int n)
{
    if (tail >= MAX - 1)
    {
        printf("Overflow\n");
        return;
    }
    arr[++tail] = n;
}

int Dequeue(void)
{
    if (tail < 0)
    {
        printf("Underflow\n");
        return -1;
    }

    int returnValue = arr[head];

    for (int i = 1; i <= tail; ++i) arr[i - 1] = arr[i];
    arr[tail] = 0;
    --tail;

    return returnValue;
}

void PrintQueue(void)
{
    printf("Queue: ");
    for (int i = 0; i < MAX; ++i) printf("%d ", arr[i]);
}

void Queue(void)
{
    printf("QUEUE\n");
    Enqueue(0);
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    Enqueue(6);
    Enqueue(7);
    Enqueue(8);
    Enqueue(9);
    printf("First dequeued value: %d\n", Dequeue());
    printf("Second dequeued value: %d\n", Dequeue());
    PrintQueue();
    printf("\n\n");
}