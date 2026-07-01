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
        vector<int> a(n); for (int &ai : a) cin >> ai;
        vector<int> b(n); for (int &bi : b) cin >> bi;

        vector<int> delta(n); 
        for (int i = 0; i < n; i++)
            delta[i] = b[i]-a[i];

        bool possible = true;
        ll prefixsum = 0;
        for(int i = 0; i < n; i++)
        {
            if (prefixsum < -(ll)delta[i]) 
            {
                possible = false;
                break;
            }
            prefixsum += delta[i];
        }

        if (possible) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }
}