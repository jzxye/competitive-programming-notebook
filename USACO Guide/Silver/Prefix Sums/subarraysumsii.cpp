#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> a(n); 
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    vector<ll> ps(n+1);
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i-1] + a[i-1];
    
    ll ans = 0;
    //unordered_map is O(n) but it is vulnerable to collisions, results in TLE
    map<ll,int> count;
    for (int i = 0; i <= n; i++)
    {
        ll target = ps[i]-x;
        if (count.find(target) != count.end())
            ans += count[target];
        
        count[ps[i]]++;
    }
    cout << ans << '\n';
}