#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int NMAX = 200000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int x[NMAX]; for (int i = 0; i < n; i++) cin >> x[i];

    ll moves = 0;
    for (int i = 1; i < n; i++)
    {
        if (x[i] < x[i-1]) 
        {
            moves += x[i-1] - x[i];
            x[i] = x[i-1];
        }
    }
    cout << moves << '\n';
}