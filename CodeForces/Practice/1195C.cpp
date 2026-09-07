#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> h1(n+1); for (int i = 1; i <= n; i++) cin >> h1[i];
    vector<int> h2(n+1); for (int i = 1; i <= n; i++) cin >> h2[i];

    vector<ll> M1(n+1); M1[0] = 0;
    vector<ll> M2(n+1); M2[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        M1[i] = max(M1[i-1], h1[i] + M2[i-1]);
        M2[i] = max(M2[i-1], h2[i] + M1[i-1]);
    }


    cout << max(M1[n], M2[n]) << '\n';
}