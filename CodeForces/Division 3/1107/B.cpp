#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int x; cin >> x;
        int digs = ceil(log10(x+1));
        int y = pow(10, digs) + 1;
        cout << y << '\n';
    }
}