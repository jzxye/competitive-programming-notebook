#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n, c; cin >> n >> c;
        vector<int> a(n); for (int &ai : a) cin >> ai;
        vector<int> b(n); for (int &bi : b) cin >> bi;

        bool possible = true;
        int t1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i]) 
            {
                t1 = INT_MAX;
                break;
            }
            t1 += a[i] - b[i];
        }

        int t2 = c;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                possible = false;
                cout << -1 << '\n';
                break;
            }
            t2 += a[i]-b[i];
        }

        if (possible) cout << min(t1, t2) << '\n';
    }
}