// Longest common subsequence
#include <iostream>
using std::cin, std::cout, std::endl;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void PrintSubsequence(int **count, char *A, char *B, int m, int n)
{
    while ((m > 0) && (n > 0))
    {
        if (A[m] == B[n])
        {
            PrintSubsequence(count, A, B, m - 1, n - 1);
            cout << A[m] << " ";
            m--;
            n--;
            return;
        }
        else if (count[m - 1][n] >= count[m][n - 1])
        {
            m--;
        }
        else
        {
            n--;
        }
    }
    return;
}

void LCS_Length(char *A, int m, char *B, int n)
{
    int **count = new int *[m];
    for (int i = 0; i < m; i++)
    {
        count[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        count[i][0] = 0;
    }
    for (int j = 0; j < n; j++)
    {
        count[0][j] = 0;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (A[i] == B[j])
            {
                count[i][j] = count[i - 1][j - 1] + 1;
            }
            else
            {
                count[i][j] = max(count[i][j - 1], count[i - 1][j]);
            }
        }
    }

    cout << "\tLCS Matrix" << endl
         << " \ty";
    for (int i = 1; i < n; i++)
    {
        cout << "\t" << B[i];
    }
    cout << endl
         << "x";
    for (int i = 0; i < m; i++)
    {
        cout << "\t" << count[0][i];
    }

    for (int i = 1; i < m; i++)
    {
        cout << endl
             << A[i] << "\t0";
        for (int j = 1; j < n; j++)
        {
            cout << "\t" << count[i][j];
        }
    }

    cout << endl
         << endl;
    cout << "Length of longest common subsequence = " << count[m - 1][n - 1];
    cout << endl;
    cout << "Subsequence = ";
    PrintSubsequence(count, A, B, m, n);

    for (int i = 0; i < m; i++)
    {
        delete count[i];
    }
    delete count;

    return;
}

int main()
{
    char *A;
    char *B;
    int x, y;

    cout << "Enter length of first sequence: ";
    cin >> x;
    A = new char[++x];
    cout << "Enter first sequence:";
    for (int i = 1; i < x; i++)
    {
        cin >> A[i];
    }

    cout << "Enter length of second sequence: ";
    cin >> y;
    B = new char[++y];
    cout << "Enter second sequence:";
    for (int i = 1; i < y; i++)
    {
        cin >> B[i];
    }

    LCS_Length(A, x, B, y);

    delete A;
    delete B;
    return 0;
}