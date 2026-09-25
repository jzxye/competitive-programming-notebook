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
    
    vector<int> ps(n+1);
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i-1] + a[i-1];
    
    int l = 0;
    int r = 0;
    ll ans = 0;
    while (l < n)
    {
        while (r < n && ps[r]-ps[l] < x)
            r++;
        
        if (ps[r] - ps[l] == x)
            ans++;
        
        l++;
    }

    cout << ans << '\n';
}