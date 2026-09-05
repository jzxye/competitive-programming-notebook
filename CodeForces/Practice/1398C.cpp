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
        string s; cin >> s;
        vector<int> a(n+1); 
        for (int i = 1; i <= n; i++)
            a[i] = s[i-1] - '0';

        vector<int> p(n+1); p[0] = 0;
        for (int i = 1; i <= n; i++)
            p[i] = p[i-1] + a[i] - 1;

        unordered_map<int, int> count;
        for (int i = 0; i <= n; i++)
            count[p[i]]++;
        
        ll good = 0;
        for (auto p : count)
        {
            good += ll(p.second) * (p.second-1) / 2;
        }

        cout << good << '\n';
    }
}