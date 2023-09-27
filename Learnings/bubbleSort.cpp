#include <iostream>
using std::cin, std::cout, std::endl, std::swap;

void bubbleSort(int *arr, int N){
    for (int i = 0; i < N-1; i++) {
        bool swapped=false;
        for (int j = 0; j < N-2; j++) {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if (!swapped) break;
    }
}

int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    cout<<"Enter elements"<<endl;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<"Before sort:";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubbleSort(arr,n);
    cout<<"After sort:";
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
