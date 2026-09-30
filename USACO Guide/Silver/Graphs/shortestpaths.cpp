#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, v; cin >> N >> M >> v;

    vector<vector<int>> adj(N+1);

    for (int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<int> dist(N+1, -1);
    vector<bool> visited(N+1);
    queue<int> q;


    q.push(v);
    visited[v] = true;
    dist[v] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int to : adj[node])
        {
            if(!visited[to])
            {
                q.push(to);
                dist[to] = dist[node] + 1;
                visited[to] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << dist[i] << ' ';
    cout << '\n';
    
}