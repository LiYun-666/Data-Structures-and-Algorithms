/*!
 * @file heap_sort.cpp
 * @author liyun2389231032@gmail.com
 * @brief 堆排序，不稳定
 * @version 0.0.1
 * @date 2022-03
 */

#include "utils.h"

// ======================================基于数组的堆排序实现=====================================
// void max_heapify(int arr[], int start, int end)
// {
//     int dad = start;
//     int son = 2 * dad + 1;
//     while (son <= end)
//     {
//         if (son + 1 <= end && arr[son] < arr[son + 1])
//             son++;
//         if (arr[dad] > arr[son]) 
//             return;
//         else
//         {
//             swap(arr[dad], arr[son]);
//             dad = son;
//             son = 2 * dad + 1;
//         }
//     }
// }

// void heap_sort(int arr[], int n)
// {
//     for (int i = n / 2 - 1; i >= 0; i--)
//         max_heapify(arr, i, n - 1);
//     for (int i = n - 1; i > 0; i--)
//     {
//         swap(arr[0], arr[i]);
//         max_heapify(arr, 0, i - 1);
//     }
// }


// ======================================基于链表的堆排序实现=====================================



void max_heapify(Node *root, Node *tail)
{
    if (root == nullptr || tail == nullptr) return;

    Node *tmp = tail->parent;
    while (tmp != nullptr)
    {
        Node *max_node;
        if (tmp->left == nullptr) max_node = tmp->right;
        else max_node = tmp->left;
        if (tmp->val < max_node->val) swap(tmp->val, max_node->val);
        tmp = tmp->pre;
    }

}
void heap_sort(Node *root, Node *tail, int n)
{
    max_heapify(root, tail);
    for (int i = 0; i < n - 1; i++)
    {
        swap(root->val, tail->val);
        max_heapify(root, tail->pre);
    }
}