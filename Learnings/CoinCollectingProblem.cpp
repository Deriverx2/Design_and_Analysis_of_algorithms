// Coin collecting problem in an m*n board
#include <iostream>
using std::cin, std::cout, std::endl;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void printCoins(int** sum, int m, int n)
{
    if(m<1 || n<1)return;
    if((sum[m][n])==sum[m-1][n]){
        printCoins(sum,m-1,n);
        cout<<m+1<<","<<n+1<<endl;
    }else if((sum[m][n])==sum[m][n-1]){
        printCoins(sum,m,n-1);
        cout<<m+1<<","<<n+1<<endl;
    }else if((sum[m][n])-1==sum[m-1][n-1]){
        printCoins(sum,m-1,n);
        cout<<m+1<<","<<n+1<<endl;
    }else{
        printCoins(sum,m,n-1);
        cout<<m+1<<","<<n+1<<endl;
    }
    return;
}

void CCP(bool** coins, int m,int n)
{
    int **sum=new int*[m];
    for(int i = 0; i <m; i++)
        sum[i] = new int[n];
    sum[0][0] = coins[0][0];
    for (int i = 1; i < n; i++)
    {
        sum[0][i] = sum[0][i-1] + coins[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        sum[i][0] = sum[i-1][0] + coins[i][0];
        for (int j=1;j < m;j++){
            sum[i][j]=max(sum[i-1][j],sum[i][j-1])+coins[i][j];
        }
    }
    cout << "Largest value=" << sum[m-1][n-1] << endl;
    printCoins(sum, m, n);
    for(int i = 0; i <m; i++)
        delete sum[i];
    delete sum;
    return;
}

int main()
{
    int m,n;
    cout << "Enter dimension of board: ";
    cin >> m >> n;
    // n = n + 1;
    bool **coins=new bool*[m];
    for(int i = 0; i <m; i++)
        coins[i] = new bool[n];
    cout<<"Enter 1 if coin is present,else zero"<<endl;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout<<"Location "<<i+1<<","<<j+1<<":";
            cin>>coins[i][j];
        }
    }
    cout<<"Board"<<endl<<" ";
    
    for (int i=0;i<m;i++){
        cout<<" "<<i+1;
    }
    cout<<endl;
    for (int i=0;i<m;i++){
        cout<<i+1;
        for (int j=0;j<n;j++){
            cout<<" "<<coins[i][j];
        }
        cout<<endl;
    }
    CCP(coins,m,n);
    for(int i = 0; i <m; i++)
        delete coins[i];
    delete coins;
    return 0;
}
