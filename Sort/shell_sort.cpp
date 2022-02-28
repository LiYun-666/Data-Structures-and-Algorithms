/*!
 * @file shell_sort.cpp
 * @author liyun2389231032@gmail.com
 * @brief 希尔排序，不稳定
 * @version 0.0.1
 * @date 2022-03
 */
void shell_sort(int arr[], int n)
{
    for (int k = n / 2; k >= 1; k /= 2)
    {
        for (int i = k; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= k && temp < arr[j - k]; j = j - k)
            {
                arr[j] = arr[j - k];
            }
            arr[j] = temp;
        }
    }
}