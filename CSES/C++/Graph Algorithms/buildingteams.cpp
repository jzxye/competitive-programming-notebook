#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    vector<vector<int>> graph(n+1);

    for (int i = 1; i <= m; i++)
    {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> ans(n+1);

    queue<int> q;
    vector<bool> visited(n+1);
    for (int i = 1; i <= n; i++)
    {
        if (visited[i]) continue;

        q.push(i);
        ans[i] = 1;
        while(!q.empty())
        {
            int node = q.front();
            for (int nb : graph[node])
            {
                if (ans[nb] == 0)
                {
                    q.push(nb);
                    ans[nb] = 3-ans[node];
                }
                else if (ans[nb] == ans[node])
                {
                    cout << "IMPOSSIBLE" << '\n';
                    return 0;
                }
            }

            visited[node] = true;
            q.pop();
        }
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}