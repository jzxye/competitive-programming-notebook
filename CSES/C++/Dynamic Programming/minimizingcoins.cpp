#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> c(n); 
    for (int i = 0; i < n; i++)
        cin >> c[i];

    vector<int> M(x+1, INT_MAX); M[0] = 0;
    for (int i = 1; i <= x; i++){
        for (int ck : c)
            if (i - ck >= 0 && M[i-ck] != INT_MAX)
                M[i] = min(M[i], 1 + M[i-ck]);
    }

    if (M[x] == INT_MAX)
        cout << -1 << '\n';
    else
        cout << M[x] << '\n';
}