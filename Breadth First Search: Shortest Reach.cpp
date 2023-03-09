#include <iostream>
#include <queue>
#include <stack>
#define MAX 1000+5
using namespace std;

int V, E;
bool visited[MAX];
int dist[MAX];
vector<int>graph[MAX];
void BFS(int s) {
	queue<int>q;
	q.push(s);
	visited[s] = true;
	dist[s] = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int& v : graph[u]) {
			if (!visited[v]) {
				visited[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}
int main() {
	int Q, u, v, s;
	cin >> Q;
	while (Q--) {
		cin >> V >> E;
		for (int i = 0; i < MAX; i++) {
			visited[i] = false;
			graph[i].clear();
			dist[i] = 0;
		}
		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		cin >> s;
		BFS(s);
		for (int i = 1; i <= V; i++) {
			if (i == s)
				continue;
			else if (visited[i])
				cout << dist[i] * 6 << " ";
			else cout << -1 << " ";
		}
		cout << endl;
	}
	return 0;
}
