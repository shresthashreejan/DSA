#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "constants.h"

void SelectionSort(void)
{
    int arr[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; ++i) arr[i] = DATA[i];
    clock_t start = clock();

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        int min = i;
        for (int j = i + 1; j < DATA_SIZE; ++j)
        {
            if (arr[min] > arr[j]) min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("SELECTION SORT\n");
    for (int i = 0; i < DATA_SIZE; ++i) printf("%d ", arr[i]);
    printf("\nExecution Time: %.10f\n", executionTime);
    printf("Time complexity: O(n^2)\n\n");
}