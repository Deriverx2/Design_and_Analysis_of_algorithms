//Incomplete
#include <iostream>
using std::cin, std::cout, std::endl;

void Bellman(int **edges, int V, int E, int source)
{
    int *dis = new int[V];
    for (int i = 0; i < V; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[source] = 0;

    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (dis[u] != INT_MAX && dis[u] + weight < dis[v])
                dis[v] = dis[u] + weight;

            // For bidirectional edges, considering both directions
            if (dis[v] != INT_MAX && dis[v] + weight < dis[u])
                dis[u] = dis[v] + weight;
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];

        if (dis[u] != INT_MAX && dis[u] + weight < dis[v])
            cout << "Graph contains a negative weight cycle" << endl;
    }

    cout << "Vertices \t Vertex Distance from Source: " << char(source + 65) << endl;
    for (int i = 0; i < V; i++)
        cout << " " << char(i + 65) << "\t\t\t" << dis[i] << endl;

    delete[] dis;
}

int main()
{
    int v;
    cout << "Enter number of edges: ";
    cin >> v;
    int **edges = new int *[v];
    for (int i = 0; i < v; i++)
        edges[i] = new int[v];
    int count = 0;
    cout << "Enter weight of edge if present,else zero" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << i + 1 << "->" << j + 1 << ":";
            cin >> edges[i][j];
            if (edges[i][j] != 0)
                count++;
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

    Bellman(edges, v, count, --source);

    for (int i = 0; i < v; i++)
        delete edges[i];
    delete edges;

    return 0;
}

// int main() {
//     int V = 5; // Number of vertices
//     int E = 6; // Number of edges

//     // Creating a 2D array (edges) dynamically
//     int **edges = new int *[E];
//     for (int i = 0; i < E; ++i)
//         edges[i] = new int[3]; // Assuming each edge has 3 elements: source, destination, weight

//     // Initializing the edges array with edge information
//     edges[0][0] = 0; edges[0][1] = 1; edges[0][2] = 4;
//     edges[1][0] = 0; edges[1][1] = 2; edges[1][2] = 1;
//     edges[2][0] = 1; edges[2][1] = 3; edges[2][2] = 1;
//     edges[3][0] = 2; edges[3][1] = 1; edges[3][2] = 2;
//     edges[4][0] = 2; edges[4][1] = 3; edges[4][2] = 5;
//     edges[5][0] = 3; edges[5][1] = 4; edges[5][2] = 3;

//     int source = 0; // Source node

//     Bellman(edges, V, E, source);

//     // Deallocating memory for the edges array
//     for (int i = 0; i < E; ++i)
//         delete[] edges[i];
//     delete[] edges;

//     return 0;
// }
