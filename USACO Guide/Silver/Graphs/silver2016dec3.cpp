#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dfs(const vector<vector<int>> &graph, vector<bool> &visited, int s)
{
    int count = 1; 
    visited[s] = true;
    for (int neighbor : graph[s])
        if (!visited[neighbor])
            count += dfs(graph, visited, neighbor);
    return count;
}
int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    int N; fin >> N;
    
    vector<int> x(N);
    vector<int> y(N);
    vector<int> p(N);

    for (int i = 0; i < N; i++)
        fin >> x[i] >> y[i] >> p[i];

    vector<vector<int>> adj(N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (p[i]*p[i] >= (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]))
                adj[i].push_back(j);
    
    int ans = 0;
    for (int s = 0; s < N; s++)
    {
        vector<bool> visited(N);
        ans = max(ans, dfs(adj, visited, s));
    }

    fout << ans << '\n';
}