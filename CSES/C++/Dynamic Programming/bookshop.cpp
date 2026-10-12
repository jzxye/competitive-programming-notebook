#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> h(n+1);
    vector<int> s(n+1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    vector<int> M(x+1);

    for (int i = 1; i <= n; i++){
        for (int p = x; p >= h[i]; p--){
            M[p] = max(M[p], M[p-h[i]] + s[i]);
        }
    }
    cout << M[x] << '\n';
}