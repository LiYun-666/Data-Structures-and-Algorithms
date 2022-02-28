/*!
 * @file insert_sort.cpp
 * @author liyun2389231032@gmail.com
 * @brief 插入排序，稳定
 * @version 0.0.1
 * @date 2022-03
 */
void insert_sort(int arr[], int n)
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