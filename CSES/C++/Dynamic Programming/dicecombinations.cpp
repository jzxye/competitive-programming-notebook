#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    vector<int> M(n+1); M[0] = 1;

    for (int i = 0; i < n; i++){
        for (int k = 1; k <= 6; k++){
            if (i + k <= n){
                M[i+k] += M[i];
                M[i+k] %= MOD;
            }
        }
    }
    cout << M[n] << '\n';    
}