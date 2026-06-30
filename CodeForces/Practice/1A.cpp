#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    double n,m,a; cin >> n >> m >> a;
    cout << (ll)ceil(n/a) * (ll)ceil(m/a) << '\n';

    //alternative solution
    //ll n,m,a; cin >> n > m >> a;
    //cout << (n+a-1)/a * (m+a-1)/a << '\n';
}