/*!
 * @file select_sort.cpp
 * @author liyun2389231032@gmail.com
 * @brief 选择排序，不稳定
 * @version 0.0.1
 * @date 2022-03
 */

#include "utils.h"

void select_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}