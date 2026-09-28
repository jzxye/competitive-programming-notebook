#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //the min number of roads is simply the number of connected components minus one

    vector<bool> visited(n+1);
        
    queue<int> q; 
    queue<int> reps;
    int components = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;

        q.push(i);
        reps.push(i);
        
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int next : adj[node])
            {
                if(visited[next])
                    continue;
                
                q.push(next);
            }

            visited[node] = true;
        }
        components++;
    }

    cout << components - 1 << '\n';

    int prev = reps.front();
    reps.pop();
    while(!reps.empty())
    {
        cout << prev << ' ' << reps.front() << '\n';
        reps.pop();
    }
}