#include <iostream>

int main()
{
    //Getting array sie
    int n;
    std::cout << "Enter array size:";
    std::cin >> n;

    //Getting elements of array
    int arr[n];
    std::cout << "Enter sorted elements of array:";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    //Getting element to search
    int element;
    std::cout << "Enter element to search:";
    std::cin >> element;

    //binary search implementation
    int mid;
    int low=0;
    int high=n-1;
    while (low>=high)
    {
        mid=(low+high)/2;
        if (element==arr[mid]){
            std::cout << "Found element at index: " << mid << std::endl;
            return 0;
        }
        else if (element<arr[mid]){
            high=mid-1;
        }
        else if(element>arr[mid]){
            low=mid+1;
        }
    }
    std::cout << "Element not found" << std::endl;
    return 0;
}
