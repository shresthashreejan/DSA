#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "constants.h"

void InsertionSort(void)
{
    int arr[DATA_SIZE];

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        arr[i] = DATA[i];
    }

    clock_t start = clock();

    for (int i = 1; i < DATA_SIZE; ++i)
    {
        int temp = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }

    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("INSERTION SORT\n");
    for (int i = 0; i < DATA_SIZE; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\nExecution Time: %.10f\n\n", executionTime);
}