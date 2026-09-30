#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct portal
{

    int a;
    int b;
    int w;

    portal()
    {
        a = b = w = -1;
    }

    portal (int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }

    bool operator<(const portal& other) const
    {
        return w < other.w;
    }
};

void dfs(const vector<vector<int>> &graph, vector<bool> &visited, int s)
{
    visited[s] = true;
    for (int to : graph[s])
        if(!visited[to])
            dfs(graph, visited, to);
}

int main() {
    ifstream fin("wormsort.in");
    ofstream fout("wormsort.out");

    int N, M; fin >> N >> M;
    vector<int> p(N+1);
    for (int i = 1; i <= N; i++)
        fin >> p[i];

    int rep = 0;
    vector<bool> misordered(N+1);
    for (int i = 1; i <= N; i++)
    {
        if(p[i] != i)
        {
            misordered[i] = true;
            rep = i;
        }
    }

    if (rep == 0)
    {
        fout << -1 << '\n';
        return 0;
    }

    //observation: sortable implies all the misordered cows must be connected via wormholes
    //does connected imply sortable? 
    // yes. if connected, there exists some tree among the edges. 
    //      fix this tree, take a leaf; by inductive hyp. the rest of the tree can be rearranged to any order
    //      we can swap the leaf with its neighbor to get all orders for n+1 nodes

    vector<portal> wormholes(M);
    for (int i = 0; i < M; i++)
    {
        int a,b,w; fin >> a >> b >> w;
        wormholes[i] = portal(a,b,w);
    }

    sort(wormholes.rbegin(), wormholes.rend());
    
    int ans = 0;
    int l = 0;
    int r = M-1;
    while(l<=r)
    {
        vector<vector<int>> adj(N+1);
        int mid = (l+r)/2;
        for (int i = 0; i <= mid; i++)
        {
            int a = wormholes[i].a;
            int b = wormholes[i].b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool> visited (N+1);
        dfs(adj, visited, rep);

        bool valid = true;
        for (int i = 1; i <= N; i++)
        {
            if (!misordered[i] || visited[i]) continue;
            valid = false;
        }

        if (valid)
        {
            ans = wormholes[mid].w;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    fout << ans << '\n';

}