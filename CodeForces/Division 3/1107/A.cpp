#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int x, y; cin >> x >> y;
        if(x % y == 0)
            cout << "YES" << '\n';
        else 
            cout << "NO" << '\n';
    }
}