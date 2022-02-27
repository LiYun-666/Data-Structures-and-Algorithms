void insert_sort(int arr[], int n) // 稳定
{
    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < arr[i - 1])
        {
            int temp = arr[i];
            int j;
            for (j = i; j > 0 && temp < arr[j - 1]; j--)
            {
                arr[j] = arr[j - 1];
            }
            arr[j] = temp;
        }
    }
}