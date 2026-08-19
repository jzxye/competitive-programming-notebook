#include <bits/stdc++.h>
using namespace std;
using ll = long long;


const int N = 100000;
int n,m;
vector<int> a(N+1); 


vector<int> adj[N+1]; 
bool visited[N+1];
int cats = 0;
int cnt = 0;

void dfs(int s, int p)
{
    if (visited[s]) return;
    visited[s] = true;

    int temp = cats;

    if (a[s] && a[p]) cats++;
    else if (a[s] && !a[p]) cats = 1;
    else cats = 0;

    if (cats > m)
    {
        cats = temp; 
        return;
    }
    if (s != 1 && adj[s].size() == 1) //leaf
        if (cats <= m) cnt++;

    for(int u : adj[s])
        dfs(u, s);
    
    cats = temp;

    return; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    a[0] = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n-1; i++)
    {
        int x,y; cin >> x >> y; 

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1,0);
    cout << cnt << '\n';
}