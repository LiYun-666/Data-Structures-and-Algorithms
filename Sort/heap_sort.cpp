/*!
 * @file heap_sort.cpp
 * @author liyun2389231032@gmail.com
 * @brief 堆排序，不稳定
 * @version 0.0.1
 * @date 2022-03
 */

#include "utils.h"

// ======================================基于数组的堆排序实现=====================================

void max_heapify(int arr[], int start, int end)
{
    int dad = start;
    int son = 2 * dad + 1;
    while (son <= end)
    {
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if (arr[dad] > arr[son]) 
            return;
        else
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}

void heap_sort_by_array(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, n - 1);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}


// ======================================基于链表的堆排序实现=====================================


bool less_than(Node *n1, Node *n2)
{
    Node *tmp1 = n1, *tmp2 = n2;
    while (tmp1 != nullptr)
    {
        if (tmp1 == tmp2) return true;
        tmp1 = tmp1->next;
    }
    return false;
}

void max_heapify(Node *start, Node *end)
{
    if (start == nullptr || end == nullptr) return;

    Node *dad = start, *son = dad->left;
    while (less_than(son, end))
    {
        if (less_than(dad->right, end) && dad->right->val > son->val) son = dad->right;
        if (dad->val > son->val) return;
        else
        {
            swap(dad->val, son->val);
            dad = son;
            son = dad->left;
        }
    }
}
void heap_sort_by_linked_list(Node *root, Node *tail, int n)
{
    Node *tmp = tail->parent;
    while (tmp != nullptr)
    {
        max_heapify(tmp, tail);
        tmp = tmp->pre;
    }
    
    tmp = tail;
    for (int i = 0; i < n - 1; i++)
    {
        swap(root->val, tail->val);
        tail = tail->pre;
        max_heapify(root, tail);
    }
    tail = tmp;
}