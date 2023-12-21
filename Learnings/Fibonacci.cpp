// Calculate nth fibonacci number(wont go beyond 46th term)
#include <iostream>
using std::cin, std::cout, std::endl;

// Dynamic implementation
int Fibonacci(int N)
{
    int fib[N + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[N];
}

// recursive implementation
//  int Fibonacci(int N){
//      if (N<=1) return N;
//      else return Fibonacci(N-1)+Fibonacci(N-2);
//  }

int main()
{
    int n;
    cout << "Enter n to calculate nth fibonacci term: ";
    cin >> n;
    int fib = Fibonacci(n);
    cout << "nth Fibonacci term: " << fib << endl;
    return 0;
}