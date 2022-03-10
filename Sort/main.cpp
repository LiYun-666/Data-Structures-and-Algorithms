/*!
 * @file main.cpp
 * @author liyun2389231032@gmail.com
 * @brief 主程序
 * @version 0.0.1
 * @date 2022-03
 */

#include "test.h"

int main()
{
    srand(time(nullptr));

    test_insert_sort();
    test_shell_sort();
    test_bubble_sort();
    test_quick_sort();
    test_select_sort();
    test_merge_sort();
    test_heap_sort_by_array();
    test_heap_sort_by_linked_list();
    
    about_me();
    return 0;
}