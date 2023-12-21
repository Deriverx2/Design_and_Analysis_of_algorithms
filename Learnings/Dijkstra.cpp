#include <iostream>
using std::cin, std::cout, std::endl;

int minDist(int *distance, bool *visted, int v)
{
    int min = INT_MAX;
    int index;
    for (int i = 0; i < v; i++)
    {
        if (!visted[i] && distance[i] < min)
        {
            min = distance[i];
            index = i;
        }
    }
    return index;
}

void Dijkstra(int **edges, int v, int source)
{
    int *distance = new int[v];
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[source] = 0;

    for (int i = 0; i < v; i++)
    {
        int m = minDist(distance, visited, v);
        visited[m] = true;

        for (int j = 0; j < v; j++)
        {
            if (!visited[j] && distance[m] != INT_MAX && edges[m][j] 
                && distance[m] + edges[m][j] < distance[j])
            {
                distance[j] = distance[m] + edges[m][j];
            }
        }
    }
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int k = 0; k < v; k++)
    {
        char str = 65 + k;
        cout << str << "\t\t\t" << distance[k] << endl;
    }

    delete[] visited;
    delete[] distance;
}

int main()
{
    int v;
    cout << "Enter number of edges: ";
    cin >> v;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
        edges[i] = new int[v];

    cout << "Enter weight of edge if present,else zero" << endl;
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
        cout << " " << char(65 + i);
    }
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << char(65 + i);
        for (int j = 0; j < v; j++)
        {
            cout << " " << edges[i][j];
        }
        cout << endl;
    }

    int source;
    cout << "Enter source edge: ";
    cin >> source;

    Dijkstra(edges, v, --source);

    for (int i = 0; i < v; i++)
        delete edges[i];
    delete edges;

    return 0;
}