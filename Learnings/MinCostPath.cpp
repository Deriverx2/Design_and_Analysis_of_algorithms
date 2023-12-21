// Minimum cost path in a matrix
#include <iostream>
using std::cin, std::cout, std::endl;

int min(int a, int b, int c)
{
    if ((a >= c) && (b >= c))
        return c;
    else if ((a > b) && (c > b))
        return b;
    else
        return a;
}

void Path(int **sum, int m, int n)
{
    cout << "\tPath\n(" << m + 1 << "," << n + 1 << ")";
    while ((m > 0) || (n > 0))
    {
        if (m == 0)
        {
            n--;
        }
        else if (n == 0)
        {
            m--;
        }
        else if ((sum[m][n - 1] >= sum[m - 1][n]) && (sum[m - 1][n - 1] >= sum[m - 1][n]))
        {
            m--;
        }
        else if ((sum[m - 1][n] >= sum[m][n - 1]) && (sum[m - 1][n - 1] >= sum[m][n - 1]))
        {
            n--;
        }
        else
        {
            m--;
            n--;
        }
        cout << "<--(" << m + 1 << "," << n + 1 << ")";
    }
    return;
}

void MCP(int **cost, int m, int n)
{
    int **sum = new int *[m];
    for (int i = 0; i < m; i++)
    {
        sum[i] = new int[n];
    }

    sum[0][0] = cost[0][0];

    for (int i = 1; i < m; i++)
    {
        sum[i][0] = sum[i - 1][0] + cost[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        sum[0][j] = sum[0][j - 1] + cost[0][j];
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            sum[i][j] = min(sum[i - 1][j], sum[i][j - 1], sum[i - 1][j - 1]) + cost[i][j];
        }
    }

    // Printing sum matrix
    cout << endl
         << "\tSum Matrix" << endl
         << " ";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << i + 1;
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << i + 1;
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << sum[i][j];
        }
        cout << endl;
    }

    cout << endl
         << "Value of minimum cost path=" << sum[m - 1][n - 1] << endl;

    cout << endl;

    Path(sum, m - 1, n - 1);

    for (int i = 0; i < n; i++)
        delete sum[i];
    delete sum;

    return;
}

int main()
{
    int m, n;
    cout << "Enter dimension of matrix: ";
    cin >> m >> n;
    int **cost = new int *[m];
    for (int i = 0; i < m; i++)
        cost[i] = new int[n];

    // recording values of matrix
    cout << "Enter cost of each cell" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Location " << i + 1 << "," << j + 1 << ":";
            cin >> cost[i][j];
        }
    }
    cout << endl;

    // Printing the matrix
    cout << endl
         << "\tCost Matrix" << endl
         << " ";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << i + 1;
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << i + 1;
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << cost[i][j];
        }
        cout << endl;
    }

    MCP(cost, m, n);

    for (int i = 0; i < m; i++)
        delete cost[i];
    delete cost;

    return 0;
}