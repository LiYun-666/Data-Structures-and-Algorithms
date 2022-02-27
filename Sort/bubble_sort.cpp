void bubble_sort(int arr[], int n) // 稳定
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j > i - 1; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                arr[j] = arr[j] ^ arr[j - 1];
                arr[j - 1] = arr[j] ^ arr[j - 1];
                arr[j] = arr[j] ^ arr[j - 1];
            }
        }
    }
}