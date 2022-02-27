#include "sort.h"
#include "utils.h"


void test_insert_sort()
{
    int n = rand() % 15;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 15;
    }
    cout << "Before sort: ";
    print_array(arr, n);

    insert_sort(arr, n);

    cout << "After sort: ";
    print_array(arr, n);
}