#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ifstream fin("fenceplan.in");
    ofstream fout("fenceplan.out");

    int N, M; fin >> N >> M;

    vector<int> x(N+1);
    vector<int> y(N+1); 
    for(int i = 1; i <= N; i++)
        fin >> x[i] >> y[i];
    
    vector<vector<int>> adj(N+1);
    for (int i = 1; i <= M; i++)
    {
        int a, b; fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = INT_MAX;
    vector<bool> visited(N+1);
    for (int s = 1; s <= N; s++)
    {
        int x_1 = INT_MAX;
        int y_1 = INT_MAX;
        int x_2 = 0;
        int y_2 = 0;
        if (visited[s]) continue;

        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int next = q.front();
            q.pop();
            visited[next] = true;

            x_1 = min(x[next], x_1);
            y_1 = min(y[next], y_1);
            x_2 = max(x[next], x_2);
            y_2 = max(y[next], y_2);

            for (int neighbor : adj[next])
                if(!visited[neighbor])
                    q.push(neighbor);
        }

        ans = min(ans, 2*(y_2-y_1+x_2-x_1));
    }
    fout << ans << '\n';
}