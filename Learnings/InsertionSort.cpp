#include<iostream>
using std::cin,std::cout,std::endl;


void insertionSort(int* arr, int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){
    
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    
    cout<<"Before sorting: ";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    insertionSort(arr,n);
    
    cout<<"After sorting: ";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
