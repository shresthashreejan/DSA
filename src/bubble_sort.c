#include <stdio.h>
#include <stdbool.h>

#include "constants.h"

void BubbleSort(void)
{
    bool swapped = false;
    int arr[DATA_SIZE];

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        arr[i] = DATA[i];
    }

    for (int i = 0; i < DATA_SIZE - 1; ++i)
    {
        swapped = false;
        for (int j = 0; j < DATA_SIZE - 1 - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    printf("BUBBLE SORT\n");
    for (int i = 0; i < DATA_SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}