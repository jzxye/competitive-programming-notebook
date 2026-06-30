#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        ll crimson = 0;
        for (int i = 1; i <= n; i++)
        {
            crimson += (ll)(n/i)*(n/i);
        }
        cout << crimson << '\n';
        
        // answer: sum (n/i)^2

    }
}