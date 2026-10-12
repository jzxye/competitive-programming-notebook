#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int Q, K; cin >> Q >> K;
    vector<int> M(K+1); M[0] = 1;
    while (Q--){
        char op; cin >> op;
        int x; cin >> x;
        if(op == '+'){ 
            for (int i = K; i >= x; i--){
                M[i] += M[i-x];
                M[i] %= MOD;
            }
        }else{
            for (int i = x; i <= K; i++){
                M[i] -= M[i-x];
                M[i] = (M[i] + MOD) % MOD;
            }
        }
        cout << M[K] << '\n';
    }
}