int main()
{
    int v;
    cout << "Enter number of edges: ";
    cin >> v;
    bool **edges = new bool *[v];
    for (int i = 0; i < v; i++)
        coins[i] = new bool[v];

    cout << "Enter 1 if edge is present,else zero" << endl;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout << "Location " << i + 1 << "," << j + 1 << ":";
            cin >> edges[i][j];
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

    CCP(edges, v);

    for (int i = 0; i < m; i++)
        delete edges[i];
    delete edges;

    return 0;
}
