#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 2019;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;
    int n = s.size();

    int mult = 1;
    vector<int> ss(n+1);
    for (int i = n-1; i >= 0; i--)
    {
        ss[i] = (ss[i+1] + (s[i]-'0') * mult) % MOD;
        mult *= 10;
        mult %= MOD;
    }

    map<int,int> count;
    for(int i = 0; i <= n; i++)
        count[ss[i]]++;

    ll ans = 0;
    for (auto p : count)
        ans += (ll) p.second * (p.second-1)/2;

    cout << ans << '\n';
}