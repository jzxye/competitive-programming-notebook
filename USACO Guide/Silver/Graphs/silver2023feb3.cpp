#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;

    vector<vector<int>> adj(N+1);

    vector<int> layover(N+1);
    for (int i = 1; i <= N; i++)
        cin >> layover[i];
    
    vector<int> time(N+1);
    
}