#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(ll n, ll m, ll a){
    if (a % n == 0 || a % m == 0){
        cout << 1 << '\n';
        return;
    }
    else{
        ll b = n*m - a;
        for (int i = 1; i < n; i++){
            if ((a%i == 0 && a/i < m) || (b%i == 0 && b/i < m)){
                cout << 2 << '\n';
                return;
            }            
        }
        cout << 3 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, a; cin >> n >> m >> a;
    solve(n,m,a);
}