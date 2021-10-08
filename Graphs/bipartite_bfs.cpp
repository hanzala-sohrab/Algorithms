#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::queue;
using std::vector;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> color;

bool bfs_check(int v)
{
    queue<int> q;
    q.push(v);
    color[v] = 0;
    
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int u: adj[node])
        {
            if (color[u] == -1)
            {
                color[u] = color[node] == 1 ? 0 : 1;
                q.push(u);
            }
            else if (color[u] == color[node])
                return false;
        }
    }
    return true;
}

bool check_bipartite()
{
    color.resize(n, -1);
    for (int i = 0; i < n; ++i)
        if (color[i] == -1)
            if (!bfs_check(i))
                return false;
    return true;
}

void graph_input()
{
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n, false);
    int i, x, y;
    for (i = 0; i < m; ++i)
    {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
}

int main()
{
    graph_input();
    if (check_bipartite())
        cout << "Bipartite\n";
    else
        cout << "Not bipartite\n";
    return 0;
}
