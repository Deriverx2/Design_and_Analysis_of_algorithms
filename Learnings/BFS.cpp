#include <iostream>
using std::cin, std::cout, std::endl;

void BFS(bool **edges, int v, int source = 0)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    
    int *queue = new int[v];
    int front = 0, rear = 0;
    queue[rear++] = source;
    visited[source] = true;
    
    cout << "\nBreadth-First Search: ";
    while (front != rear)
    {
        int curr = queue[front++];
        cout << curr + 1 << " ";
        for (int i = 0; i < v; i++)
        {
            if (edges[curr][i] && !visited[i])
            {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
    delete[] visited;
    delete[] queue;
}

int main()
{
    int v;
    cout << "Enter number of edges: ";
    cin >> v;
    bool **edges = new bool *[v];
    for (int i = 0; i < v; i++)
        edges[i] = new bool[v];

    cout << "Enter 1 if edge is present,else zero" << endl;
    for (int i = 0; i < v; i++)
    {
        edges[i][i] = 0;
        for (int j = 0; j < i; j++)
        {
            cout << i + 1 << "->" << j + 1 << ":";
            cin >> edges[i][j];
            edges[j][i] = edges[i][j];
        }
    }
    cout << endl;

    cout << endl
         << "\tAdjancency Matrix" << endl
         << " ";
    for (int i = 0; i < v; i++)
    {
        cout << " " << i + 1;
    }
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i + 1;
        for (int j = 0; j < v; j++)
        {
            cout << " " << edges[i][j];
        }
        cout << endl;
    }
    int source;
    cout << "Enter source edge: ";
    cin >> source;

    BFS(edges, v, --source);

    for (int i = 0; i < v; i++)
        delete edges[i];
    delete edges;

    return 0;
}