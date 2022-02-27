int partition(int arr[], int left, int right)
{
    int pivot = arr[left];
    while (left < right)
    {
        while (left < right && arr[right] >= pivot)
            right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot)
            left++;
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}
void quick_sort(int arr[], int left, int right) // 不稳定
{
    if (left < right) // 递归终止条件
    {
        int pivot_pos = partition(arr, left, right);
        quick_sort(arr, left, pivot_pos - 1);
        quick_sort(arr, pivot_pos + 1, right);
    }
}