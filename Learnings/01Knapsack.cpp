// 01knapsack problem
#include <iostream>
using std::cin, std::cout, std::endl;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// Backtracking the items which are choosen to get max value
void Items(int **sum, int *values, int *weights, int m, int n)
{
    cout << "\tChoosen Item and Value\n";
    while ((m > 0) && (n > 0))
    {
        if (sum[m][n] == sum[m][n - 1])
        {
            do
            {
                n--;
            } while (sum[m][n] == sum[m][n - 1]);
        }
        else if (sum[m][n] == sum[m - 1][n])
        {
            do
            {
                m--;
            } while (sum[m][n] == sum[m - 1][n]);
        }
        cout << m << "\t" << values[m] << endl;
        n -= weights[m];
        m--;
    }
    return;
}

// Knapsack function
// parameters:item value, item weight, item count, capacity of knapsack
void Knapsack(int *values, int *weights, int m, int c)
{

    int **sum = new int *[m];
    for (int i = 0; i < m; i++)
    {
        sum[i] = new int[c];
    }

    sum[0][0] = 0;

    for (int i = 1; i < m; i++)
    {
        sum[i][0] = 0;
    }
    for (int j = 1; j < c; j++)
    {
        sum[0][j] = 0;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (j - weights[i] >= 0)
            {
                sum[i][j] = max(sum[i - 1][j], values[i] + sum[i - 1][j - weights[i]]);
            }
            else
            {
                sum[i][j] = sum[i - 1][j];
            }
        }
    }

    // Printing knapsack matrix
    cout << endl
         << "\tKnapsack Matrix" << endl
         << " ";
    for (int i = 0; i < c; i++)
    {
        cout << "\t" << i;
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << i;
        for (int j = 0; j < c; j++)
        {
            cout << "\t" << sum[i][j];
        }
        cout << endl;
    }

    cout << endl
         << "Maximum Knapsack Value=" << sum[m - 1][c - 1] << endl;

    cout << endl;

    Items(sum, values, weights, m - 1, c - 1);

    for (int i = 0; i < c; i++)
        delete sum[i];
    delete sum;

    return;
}

int main()
{
    int m;
    cout << "Enter number of items: ";
    cin >> m;
    m++;
    int *values = new int[m];
    int *weights = new int[m];
    values[0] = weights[0] = 0;
    for (int i = 1; i < m; i++)
    {
        cout << "Enter weight of item " << i << ": ";
        cin >> weights[i];
        cout << "Enter value of item " << i << ": ";
        cin >> values[i];
    }

    cout << endl;

    // Printing the value and weight of items
    cout << endl
         << "Item\tWeight\tValue" << endl;
    for (int i = 1; i < m; i++)
    {
        cout << i << "\t" << weights[i] << "\t" << values[i] << endl;
    }
    cout << endl;

    int capacity;
    cout << "Enter capacity: ";
    cin >> capacity;

    Knapsack(values, weights, m, ++capacity);

    delete values;
    delete weights;

    return 0;
}