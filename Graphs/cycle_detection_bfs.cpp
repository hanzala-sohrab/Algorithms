/*
 * Cycle detection in undirected graph using BFS
 *
 */
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using std::cin;
using std::cout;
using std::vector;
using std::queue;
using std::pair;

vector<vector<int>> adj;
vector<bool> visited;
int n, m;

bool bfs(int v)
{
    queue<pair<int, int>> q;
    visited[v] = true;
    q.push({v, -1});

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        for (int u: adj[p.first])
        {
            if (visited[u] and u != p.second)
                return true;
            else if (!visited[u])
            {
                visited[u] = true;
                q.push({u, p.first});
            }
        }
    }
    return false;
}

bool check()
{
    int i;
    for (i = 0; i < n; ++i)
        if (!visited[i])
            if (bfs(i))
                return true;
    return false;
}

void graph_input()
{
    cin >> n >> m;
    adj.resize(n);
    visited.resize(n, false);
    int i, x, y;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
}

int main()
{
    graph_input();
    if (check())
        cout << "Cycle found\n";
    else
        cout << "No cycle found\n";
    return 0;
}
