#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dfs(const vector<vector<int>> &graph, vector<bool> &visited, int s, int i, int j)
{
    int count = 1;
    visited[s] = true;
    
    for(int neighbor : graph[s])
        if(!visited[neighbor] && !((s == i && neighbor == j) || (s == j && neighbor == i)))
            count += dfs(graph, visited, neighbor, i, j);
    return count;
}

void solve(const vector<vector<int>> &graph, int p, int c)
{
    for (int i = 0; i < p; i++)
    {
        for (int j : graph[i])
        {
            vector<bool> visited(p);
            
            if (dfs(graph, visited, 0, i, j )!= p)
            {
                cout << "Yes" << '\n';
                return;
            }
        }
    }
    cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        int p, c; cin >> p >> c;
        if (p == 0 && c == 0)
            break;

        vector<vector<int>> adj(p);
        for (int i = 0; i < c; i++)
        {
            int a,b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        solve(adj, p, c);
    }
}