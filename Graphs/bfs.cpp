/*
 * Cycle detection in undirected graph using BFS
 */
#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::cin;
using std::vector;
using std::queue;

vector<vector<int>> adj;
vector<bool> visited;
int n, m;

void bfs(int start=0) {
	vector<bool> visited(n, false);
	queue<int> q;
	vector<int> distance(n, -1);
	q.push(start);
	visited[start] = 1;
	distance[start] = 0;
	int i = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto it: adj[u])
			if (!visited[it])
			{
				q.push(it);
				visited[it] = true;
				distance[it] = i;
			}
		++i;
	}
	for (auto it: distance)
		cout << it << ' ';
	cout << '\n';
}

void graph_input() {
	cin >> n >> m;
	adj.resize(n);
	int i, x, y;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	bfs(1);
}

int main() {
	graph_input();
	return 0;
}
