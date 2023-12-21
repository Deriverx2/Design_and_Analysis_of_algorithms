#include <iostream>
using std::cin, std::cout, std::endl;

void DFS(bool **edges, bool *visited, int v, int source = 0)
{
    visited[source] = true;
    cout << source + 1 << " ";
    for (int i = 0; i < v; i++)
    {
        if (edges[source][i] && !visited[i])
        {
            DFS(edges, visited, v, i);
        }
    }
}

void DFS_visit(bool **edges, int *queue, bool *visited, int u)
{
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
        for (int j = 0; j < v; j++)
        {
            cout << i + 1 << "->" << j + 1 << ":";
            cin >> edges[i][j];
        }
    }
    cout << endl;

    cout << endl
         << "\tAdjancency Matrix" << endl
         << " ";
    for (int i = 0; i < v; i++)
    {
        cout << " " << i ;
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

    cout << "\nDepth-First Search: ";
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    DFS(edges, visited, v, --source);

    delete[] visited;
    for (int i = 0; i < v; i++)
        delete edges[i];
    delete edges;

    return 0;
}