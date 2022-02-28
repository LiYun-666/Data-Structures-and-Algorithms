/*!
 * @file bubble_sort.cpp
 * @author liyun2389231032@gmail.com
 * @brief 冒泡排序，稳定
 * @version 0.0.1
 * @date 2022-03
 */

#include "utils.h"

void bubble_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j > i - 1; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}