void select_sort(int arr[], int n) // 不稳定
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
        if (min != i)
        {
            arr[i] = arr[i] ^ arr[min];
            arr[min] = arr[i] ^ arr[min];
            arr[i] = arr[i] ^ arr[min];
        }
    }
}