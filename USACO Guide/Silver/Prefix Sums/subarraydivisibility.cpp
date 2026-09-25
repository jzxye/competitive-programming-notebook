#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<int> ps(n+1); 
    for (int i = 1; i<= n; i++)
        ps[i] = ((ps[i-1] + a[i-1])%n+n)%n;

    unordered_map<int,int> count;
    for (int r : ps)
        count[r]++;

    ll ans = 0;
    for (auto p : count)
    {
        int occ = p.second;
        ans += (ll)occ * (occ-1)/2;
    }
    cout << ans << '\n';
}