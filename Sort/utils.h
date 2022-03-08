/*!
 * @file utils.h
 * @author liyun2389231032@gmail.com
 * @brief 工具文件，为排序算法提供一些工具，如 swap 函数等
 * @version 0.0.1
 * @date 2022-03
 */

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 堆的结点
struct Node
{
    int val;
    Node *left, *right, *parent;
    Node *pre, *next;
    Node() : val(0), left(nullptr), right(nullptr), parent(nullptr), pre(nullptr), next(nullptr) {}
    Node(int x): val(x), left(nullptr), right(nullptr), parent(nullptr), pre(nullptr), next(nullptr) {}
    Node(int x, Node *left): val(x), left(left), right(nullptr), parent(nullptr), pre(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right): val(x), left(left), right(right), parent(nullptr), pre(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *parent): val(x), left(left), right(right), parent(parent), pre(nullptr), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *parent, Node *pre): val(x), left(left), right(right), parent(parent), pre(pre), next(nullptr) {}
    Node(int x, Node *left, Node *right, Node *parent, Node *pre, Node *next): val(x), left(left), right(right), parent(parent), pre(pre), next(next) {}
};

// 交换
void swap(int &a, int &b);

// 打印数组
void print_array(int arr[], int n);

// 打印堆
void print_heap(Node *root);

// 关于我
void about_me();