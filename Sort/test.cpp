#include "sort.h"

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

void test_heap_sort_by_array()
{
    cout << "====================test heap_sort_by_array====================" << endl;

    int n = 5 + rand() % 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 20;
    }

    cout << "Before sort: ";
    print_array(arr, n);

    heap_sort_by_array(arr, n);

    cout << "After sort: ";
    print_array(arr, n);
}

void test_heap_sort_by_linked_list()
{
    cout << "====================test heap_sort_by_linked_list====================" << endl;
    
    int n = 5 + rand() % 5;
    Node *root = new Node(rand() % 20), *tail = root;
    for (int i = 1; i < n; i++)
    {
        // 五个指针，左孩子 右孩子 父亲 (前驱) (后继)
        tail->next = new Node(rand() % 20, nullptr, nullptr, nullptr, tail, nullptr);
        if (tail->parent == nullptr) // 根结点
        {
            tail->left = tail->next;
            tail->next->parent = tail;
        }
        else if (tail->parent->left != nullptr && tail->parent->right == nullptr) // 孩子数为1
        {
            // tail->next->parent = tail->parent;
            tail->parent->right = tail->next;
            tail->next->parent = tail->parent;
        }
        else // 孩子数为2
        {
            tail->parent->next->left = tail->next;
            tail->next->parent = tail->parent->next;
        }
        tail = tail->next;
    }
    cout << "Before sort: ";
    print_heap(root);
    heap_sort_by_linked_list(root, tail, n);
    cout << "After sort: ";
    print_heap(root);
}