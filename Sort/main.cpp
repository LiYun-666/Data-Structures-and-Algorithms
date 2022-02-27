#include "test.h"

int main()
{
    srand(time(nullptr));
    test_insert_sort();



    about_me();
    return 0;
}

// #include <iostream>



// int main()
// {
//     int arr[10] = {1, 4, 2, 8, 7, 6, 0, 5, 3, 9};
//     quick_sort(arr, 0, 9);
//     for (int i = 0; i < 10; i++)
//     {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
// }