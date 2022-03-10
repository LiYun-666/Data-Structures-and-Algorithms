/*!
 * @file sort
 * @author liyun2389231032@gmail.com
 * @brief 排序函数声明
 * @version 0.0.1
 * @date 2022-03
 */

#pragma once

#include "utils.h"

void insert_sort(int arr[], int n);

void bubble_sort(int arr[], int n);

void select_sort(int arr[], int n);

void shell_sort(int arr[], int n);

void quick_sort(int arr[], int left, int right);

void merge_sort(int arr[], int left, int right);

void heap_sort_by_array(int arr[], int n);

void heap_sort_by_linked_list(Node *root, Node *tail, int n);