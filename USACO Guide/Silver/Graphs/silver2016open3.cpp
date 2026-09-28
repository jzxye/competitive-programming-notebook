#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dfs(const vector<vector<int>> &graph, vector<bool> &visited,  int s)
{
    int count = 1;
    visited[s] = true;
    for (int neighbor : graph[s])
        if (!visited[neighbor])
            count += dfs(graph, visited, neighbor);

    return count;
}

int main() {
    ifstream fin("closing.in");
    ofstream fout("closing.out");

    int N, M; fin >> N >> M;

    vector<vector<int>> adj(N+1);

    for (int i = 0; i < M; i++)
    {
        int a,b; fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> order(N+1);
    for (int i = 1; i <= N; i++)
        fin >> order[i];

    vector<bool> initial(N+1);
    if (dfs(adj, initial, order[N]) == N)
        fout << "YES" << '\n';
    else
        fout << "NO" << '\n';
    
    for (int i = 1; i < N; i++)
    {
        vector<bool> visited(N+1);
        for (int j = 1; j <= i; j++)
            visited[order[j]] = true;

        if (dfs(adj, visited, order[N]) == N-i)
            fout << "YES" << "\n";
        else
            fout << "NO" << '\n';
    }
}