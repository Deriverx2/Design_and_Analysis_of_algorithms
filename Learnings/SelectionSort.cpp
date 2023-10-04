#include<iostream>
using std::cin,std::cout,std::endl,std::swap;

void selectionSort(int* arr, int n){
    for (int i = 0; i < n; i++) {
        int minIndex = i;
        int j = i + 1;
        while(j < n ){
            if (arr[minIndex] > arr[j]) minIndex = j;
            j++;
        }
        if(minIndex != i) swap(arr[i], arr[minIndex]);
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
    
    selectionSort(arr,n);
    
    cout<<"After sorting: ";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
