#include <iostream>
using std::cin, std::cout, std::endl;

//Iterative implementation
// int GCD(int m, int n)
// {
//     int r;
//     while (n != 0)
//     {
//         r = m % n;
//         m = n;
//         n = r;
//     }
//     return m;
// }

//recursive implementation
int GCD(int m, int n){
    if (n==0) return m;
    else return GCD(n, m%n);
}

int main()
{
    int a, b;
    cout << "Enter two numbers to compute GCD: ";
    cin >> a >> b;
    int gcd = GCD(a, b);
    cout << "GCD: " << gcd << endl;
    return 0;
}