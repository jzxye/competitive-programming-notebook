#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int k; cin >> k;
        vector<int> c(k); for (int &ci : c) cin >> ci;

        int doubles = 0;
        int triples = 0;
        for (int ci : c)
        {
            doubles += ci >= 2;
            triples += ci >= 3;
        }
        if (doubles >= 2 || triples >= 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}