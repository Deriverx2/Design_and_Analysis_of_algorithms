//Algorithm to calculate prime numbers
#include <iostream>
#include <cmath>
using std::cin, std::cout, std::endl;

bool* Sieve(int n)
{
    bool* arr=new bool[n+1];
    for (int i = 0; i < n + 1; i++)
    {
        arr[i] = 1;
    }
    arr[0] = 0;
    arr[1] = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (arr[i])
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
    bool* prime = Sieve(n);
    cout<<"Prime numbers:";
    for (int i = 0; i < n + 1; i++)
    {
        if (prime[i])
        {
            cout<<i<<' ';
        }
    }
    delete[] prime;
    return 0;
}
