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
    test_heap_sort();
    
    about_me();
    return 0;
}