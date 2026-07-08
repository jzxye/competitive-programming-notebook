#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for (int &ai : a) cin >> ai;

    vector<ll> ps(n); 
    ps[0] = a[0];
    for (int i = 1; i < n; i++)
        ps[i] = ps[i-1] + a[i];

    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int q; cin >> q;

        int pile = -1;
        for (int b = n; b >= 1; b /= 2)
            while(pile + b < n && ps[pile+b] < q) pile += b;
        pile+=2;

        cout << pile << '\n';
    }

}