#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n); for (int &vi : v) cin >> vi;
    vector<int> u(n); 
    for (int i = 0; i < n; i++) 
        u[i] = v[i];
    sort(u.begin(), u.end());

    vector<ll> pv(n+1); pv[0] = 0; for (int i = 1; i <= n; i++) pv[i] = pv[i-1] + v[i-1];
    vector<ll> pu(n+1); pu[0] = 0; for (int i = 1; i <= n; i++) pu[i] = pu[i-1] + u[i-1];


    int m; cin >> m;
    while(m--)
    {
        int type; cin >> type;
        int l, r; cin >> l >> r;

        if (type == 1)
            cout << pv[r] - pv[l-1] << '\n';
        else if (type == 2)
            cout << pu[r] - pu[l-1] << '\n';
    }


}