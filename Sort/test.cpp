#include "sort.h"
#include "utils.h"

void test_insert_sort()
{
    cout << "====================test insert_sort====================" << endl;

    int n = 5 + rand() % 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
    }

    cout << "Before sort: ";
    print_array(arr, n);

    insert_sort(arr, n);

    cout << "After sort: ";
    print_array(arr, n);
}

void test_shell_sort()
{
    cout << "====================test shell_sort====================" << endl;

    int n = 5 + rand() % 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
    }

    cout << "Before sort: ";
    print_array(arr, n);

    shell_sort(arr, n);

    cout << "After sort: ";
    print_array(arr, n);
}

void test_bubble_sort()
{
    cout << "====================test bubble_sort====================" << endl;

    int n = 5 + rand() % 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
    }

    cout << "Before sort: ";
    print_array(arr, n);

    bubble_sort(arr, n);

    cout << "After sort: ";
    print_array(arr, n);
}

void test_quick_sort()
{
    cout << "====================test quick_sort====================" << endl;

    int n = 5 + rand() % 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
    }

    cout << "Before sort: ";
    print_array(arr, n);

    quick_sort(arr, 0, n - 1);

    cout << "After sort: ";
    print_array(arr, n);
}

void test_select_sort()
{
    cout << "====================test select_sort====================" << endl;

    int n = 5 + rand() % 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
    }

    cout << "Before sort: ";
    print_array(arr, n);

    select_sort(arr, n);

    cout << "After sort: ";
    print_array(arr, n);
}

void test_merge_sort()
{
    cout << "====================test merge_sort====================" << endl;

    int n = 5 + rand() % 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
    }

    cout << "Before sort: ";
    print_array(arr, n);

    merge_sort(arr, 0, n - 1);

    cout << "After sort: ";
    print_array(arr, n);
}

void test_heap_sort()
{
    cout << "====================test heap_sort====================" << endl;

    // int n = 5 + rand() % 5;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     arr[i] = rand() % 20;
    // }

    // cout << "Before sort: ";
    // print_array(arr, n);

    // heap_sort(arr, n);

    // cout << "After sort: ";
    // print_array(arr, n);
    
    int n = 5 + rand() % 5;
    Node *root = new Node(rand() % 20), *tail = root;
    for (int i = 1; i < n; i++)
    {
        tail->next = new Node(rand() % 20, nullptr, nullptr, nullptr, tail, nullptr);
        if (tail->parent->left != nullptr && tail->parent->right == nullptr) //孩子数等于1
        {
            tail->next->parent = tail->parent;
        }
        else if () // 孩子数为0
        else // 孩子数为2
    }
}