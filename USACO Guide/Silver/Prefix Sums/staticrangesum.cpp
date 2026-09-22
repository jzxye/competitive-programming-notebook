#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, Q; cin >> N >> Q;
    vector<int> a(N+1); 
    for (int i = 1; i <= N; i++)
        cin >> a[i];

    vector<ll> ps(N+1); ps[0] = 0;
    for (int i = 1; i <= N; i++)
        ps[i] = ps[i-1]+a[i];

    while (Q--)
    {
        int l, r; cin >> l >> r;
        cout << ps[r]-ps[l] << '\n';
    }

}