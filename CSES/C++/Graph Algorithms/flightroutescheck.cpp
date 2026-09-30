#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(const vector<vector<int>> &graph, vector<bool> &visited, int s)
{
    visited[s] = true;
    for (int to : graph[s])
        if(!visited[to])
            dfs(graph, visited, to);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<vector<int>> adj1(n+1);
    vector<vector<int>> adj2(n+1);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }

    vector<bool> visited1(n+1);
    vector<bool> visited2(n+1);
    dfs(adj1, visited1, 1);
    dfs(adj2, visited2, 1);

    bool valid = true;
    
    for (int i = 1; i <= n; i++)
    {
        if(!visited1[i])
        {
            cout << "NO" << '\n';
            cout << 1 << ' ' << i << '\n';
            valid = false;
            break;
        }
        else if (!visited2[i])
        {
            cout << "NO" << '\n';
            cout << i << ' ' << 1 << '\n';
            valid = false;
            break;
        }
    }

    if (valid)
        cout << "YES" << '\n';
}