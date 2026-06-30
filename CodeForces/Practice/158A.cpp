#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k; cin >> n >> k;
    vector<int> a(n); for (int &ai : a) cin >> ai;

    int z = -1;
    for (int b = n; b >= 1; b /= 2)
        while (z+b < n && a[z+b] != 0) z += b;
    z++;

    int kk = k;
    while (kk < n && a[kk] == a[k-1])
        kk++;

    cout << min(z,kk) << '\n';
}