#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "constants.h"
#include "merge_sort.h"

void MergeSort(void)
{
    int arr[DATA_SIZE];
    for (int i = 0; i < DATA_SIZE; ++i) arr[i] = DATA[i];

    int* newArr = Divide(arr);
}

int* Divide(int* arr)
{
    int midPoint = DATA_SIZE / 2;
    int* leftArr = (int*)malloc(midPoint * sizeof(int));
    int* rightArr = (int*)malloc((DATA_SIZE - midPoint) * sizeof(int));

    for (int i = 0; i < DATA_SIZE; ++i)
    {
        if (i < midPoint)
        {
            leftArr[i] = arr[i];
        }
        else
        {
            rightArr[i - midPoint] = arr[i];
        }
    }

    for (int i = 0; i < midPoint; ++i)
    {
        printf("%d ", leftArr[i]);
    }
    printf("\n");
    for (int i = 0; i < DATA_SIZE - midPoint; ++i)
    {
        printf("%d ", rightArr[i]);
    }

    return leftArr;
}