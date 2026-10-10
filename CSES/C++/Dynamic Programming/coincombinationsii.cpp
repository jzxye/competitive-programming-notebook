#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> c(n); 
    for(int i = 0; i < n; i++)
        cin >> c[i];

    vector<int> M(x+1); M[0] = 1;
    for (int ci : c){
        for (int k = ci; k <= x; k++){
            M[k] += M[k-ci];
            M[k] %= MOD;
        }
    }

    cout << M[x] << '\n';
}