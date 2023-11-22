//Longest common subsequence

#include <iostream>
using std::cin, std::cout, std::endl;


void LCS_Length(char* A, char* B, int m,int n){
    int count[m][n];
    for (int i = 0; i < m; i++) {
        count[i][0]=0;
    }
    for (int i = 0; i < n; i++) {
        count[0][i]=0;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; i < n; j++) {
            if (A[i]==B[j]){
                count[i][j]=count[i-1][j-1]+1;
            }
            else if (count[i-1][j]>=count[i][j-1]){
                count[i][j]=count[i-1][j];
            }
            else{
                count[i][j]=count[i][j-1];
            }
        }   
    }
    cout<<count[m-1][n-1];
    
    return;
}

int main()
{
    char* A;
    char* B;
    int x,y;
    
    cout<<"Enter length of first sequence: ";
    cin>>x;
    A=new char[x];
    cout<<"Enter first sequence:";
    for (int i = 0; i < x; i++) {
        cin>>A[i];
    }
    
    cout<<"Enter length of second sequence: ";
    cin>>y;
    B=new char[y];
    cout<<"Enter second sequence:";
    for (int i = 0; i < y; i++) {
        cin>>B[i];
    }
    
    LCS_Length(A,B,x,y);
    
    delete A;
    delete B;
    return 0;
}
