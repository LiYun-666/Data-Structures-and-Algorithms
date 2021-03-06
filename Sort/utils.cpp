/*!
 * @file utils.cpp
 * @author liyun2389231032@gmail.com
 * @brief 工具函数实现
 * @version 0.0.1
 * @date 2022-03
 */

#include "utils.h"


// 交换
void swap(int &a, int &b)
{
    if (a != b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

// 打印数组
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 打印堆
void print_heap(Node *root)
{
    Node *tmp = root;
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

// 关于我
void about_me()
{
    cout << "Welcome! Thanks for your support!" << endl
    << "My Email: 2389231032@qq.com" << endl
    << "My Email: liyun2389231032@gmail.com" << endl
    << "My GitHub: https://github.com/liyun-666" << endl
    << "My Gitee: https://gitee.com/liyun-666" << endl
    << "My Blog: https://liyun-666.github.io" << endl;
}