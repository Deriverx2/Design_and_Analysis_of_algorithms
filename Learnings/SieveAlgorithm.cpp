//Algorithm to calculate prime umbers
#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl;

int* Sieve(int n)
{
    int* arr=new int[n+1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = i;
    }
    arr[0] = 0;
    arr[1] = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (arr[i] != 0)
        {
            int j = i * i;
            while (j <= n)
            {
                arr[j] = 0;
                j += i;
            }
        }
    }

    return arr;
}

int main()
{
    cout<<"Calculate primes in a given range"<<endl;
    int n;
    cout << "Enter a positive numbers: ";
    cin >> n;
    int* prime = Sieve(n);
    cout<<"Prime numbers:";
    for (int i = 0; i < n + 1; i++)
    {
        if (prime[i] != 0)
        {
            cout<<prime[i]<<' ';
        }
    }
    delete[] prime;
    return 0;
}
