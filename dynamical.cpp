#include <iostream>

int main()
{
    // Dynamically allocate an array of size 10^9
    int *arr = new int[100000000];

    // Use the array (for demonstration purposes)
    std::cout << "First element: " << arr[0] << std::endl;
    std::cout << "Last element: " << arr[99999999] << std::endl;

    // Don't forget to free the allocated memory
    delete[] arr;

    return 0;
}
