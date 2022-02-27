void shell_sort(int arr[], int n) // 不稳定
{
    for (int k = n / 2; k >= 1; k /= 2)
    {
        for (int i = k; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j > 0 && temp < arr[j - k]; j = j - k)
            {
                arr[j] = arr[j - k];
            }
            arr[j] = temp;
        }
    }
}