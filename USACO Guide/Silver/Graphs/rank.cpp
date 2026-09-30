#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(const vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &undetermined, int root, int s)
{
    visited[s] = true;
    for (int to : graph[s])
        if (to == root)
            undetermined[to] = true;
        else if (!visited[to])
            dfs(graph, visited, undetermined, root, to);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;

    vector<vector<int>> adj(N+1);
    for (int i = 0; i < K; i++)
    {
        int a, b, s_a, s_b; cin >> a >> b >> s_a >> s_b;
        if(s_a>s_b)
            adj[a].push_back(b);
        else
            adj[b].push_back(a);
    }

    
    //vector<bool> visited(N+1);
    vector<bool> undetermined(N+1);
    for (int s = 1; s <= N; s++)
    {
        //if (visited[s]) continue;
        vector<bool> visited(N+1);
        dfs(adj, visited, undetermined, s, s);
    }

    int count = 0;
    for (int i = 1; i <= N; i++)
        count += undetermined[i];
    
    cout << count << '\n';
}