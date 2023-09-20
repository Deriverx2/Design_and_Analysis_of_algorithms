#include <iostream>

using std::cin, std::cout, std::endl, std::swap;

int partition(int *arr, int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);

    return i + 1;
}

void quickSort(int *arr, int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot - 1);
        quickSort(arr, pivot+1, r);
    }
}

int main()
{
    int N;
    cout << "Enter number of Elements:";
    cin >> N;
    int arr[N];
    cout << "Enter elements: ";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sort:";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, 0, N - 1);
    cout << "After sort:";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
