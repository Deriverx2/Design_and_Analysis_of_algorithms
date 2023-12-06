#include <iostream>

// linear search function
int linearSearch(int *arr, int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    // getting array size
    int n;
    std::cout << "Enter array size:";
    std::cin >> n;

    // geting elements of array
    int arr[n];
    std::cout << "Enter elements of array:";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    // getting element to search
    int element;
    std::cout << "Enter element to search:";
    std::cin >> element;

    int index = linearSearch(arr, n, element);
    if (index == -1)
    {
        std::cout << "Element not found" << std::endl;
    }
    else
    {
        std::cout << "Found element at index: " << index;
    }
    return 0;
}
