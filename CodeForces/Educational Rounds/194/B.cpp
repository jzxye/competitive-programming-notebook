#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        ll x,y,k; cin >> x >> y >> k;

        ll i = 0;
        ll total = 0;
        while (i < k && y+i >= 2*(x+i))
        {
            total += (y+i)%(x+i);
            i++;
        }
        total += (y-x)*(k-i);

        cout << total << '\n';
    }
}