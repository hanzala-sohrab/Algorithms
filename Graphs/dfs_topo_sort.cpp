#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
stack<int> s;

void explore(int u) {
    visited[u] = true;
    for (int v: adj[u])
        if (!visited[v])
            explore(v);
    s.push(u);
}

void topo_sort() {
    visited.resize(n, false);
    for (int i = 0; i < n; ++i)
        if (!visited[i])
            explore(i);
}

void graph_input() {
    cin >> n >> m;
    int i, x, y;
    adj.resize(n);
    for (i = 0; i < m; ++i)
    {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
    }
}

void output() {
    while (!s.empty())
    {
        cout << s.top() + 1 << ' ';
        s.pop();
    }
}

int main() {
    graph_input();
    topo_sort();
    output();
    return 0;
}
