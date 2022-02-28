/*!
 * @file heap_sort.cpp
 * @author liyun2389231032@gmail.com
 * @brief 堆排序，不稳定
 * @version 0.0.1
 * @date 2022-03
 */

#include "utils.h"

void max_heapify(int arr[], int start, int end)
{
    int dad = start;
    int son = 2 * dad + 1;
    while (son <= end)
    {
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if (arr[dad] > arr[son]) 
            return;
        else
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, n - 1);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}