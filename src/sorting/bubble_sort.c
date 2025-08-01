#include <stdio.h>
#include <time.h>

#include "bubble_sort.h"
#include "constants.h"

void BubbleSort(void)
{
    int arr[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; ++i) arr[i] = DATA[i];
    clock_t start = clock();

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        for (int j = 0; j < DATA_SIZE - i; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    clock_t end = clock();
    double executionTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("BUBBLE SORT\n");
    for (int i = 0; i < DATA_SIZE; ++i) printf("%d ", arr[i]);
    printf("\nExecution Time: %.10f\n", executionTime);
    printf("Time complexity: O(n^2)\n");
}