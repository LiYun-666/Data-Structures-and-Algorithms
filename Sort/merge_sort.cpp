/*!
 * @file merge_sort.cpp
 * @author liyun2389231032@gmail.com
 * @brief 归并排序，稳定
 * @version 0.0.1
 * @date 2022-03
 */

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k = 0, n = right - left + 1;
    int *temp = new int[n];
    for (i = left, j = mid + 1; i <= mid && j <= right; k++)
    {
        if (arr[i] <= arr[j])
            temp[k] = arr[i++];
        else
            temp[k] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (k = 0; k < n; k++)
    {
        arr[left++] = temp[k];
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}