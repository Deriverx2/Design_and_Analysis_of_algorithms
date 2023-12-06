#include <iostream>
using std::cin, std::cout, std::endl, std::swap;

int pivot(int *arr, int l, int r)
{
    int pivote = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivote)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[++i], arr[r]);

    return i;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int p = pivot(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

int main()
{
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Before sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "After sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
