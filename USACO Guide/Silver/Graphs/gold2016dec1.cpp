#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int COORD_MAX = 25000;

int dfs(const vector<vector<int>> &graph, vector<bool> &visited, int s)
{
    int count = 1;
    visited[s] = true;
    for (int to : graph[s])
        if(!visited[to])
            count += dfs(graph, visited, to);
    return count;
}

int main() {
    ifstream fin("moocast.in");
    ofstream fout("moocast.out");

    int N; fin >> N;
    vector<int> x(N);
    vector<int> y(N);
    for (int i = 0; i < N; i++)
        fin >> x[i] >> y[i];

    //binary search + dfs

    int ans = INT_MAX;

    int l = 0;
    int r = COORD_MAX*COORD_MAX;

    while (l <= r)
    {
        int X = (l+r)/2;
        vector<vector<int>> adj(N);

        for (int i = 0; i < N-1; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                if (X >= (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> visited(N);

        int val = dfs(adj, visited, 0);
        if (val == N)
        {
            ans = min(ans, X);
            r = X-1;
        }
        else
        {
            l = X+1;
        }
    }

    fout << ans << '\n';
}