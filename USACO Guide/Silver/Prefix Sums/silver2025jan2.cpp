#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int N, M; cin >> N >> M;

        vector<int> a(N+1); 
        for (int i = 1; i <= N; i++)
        { 
            cin >> a[i];
            a[i] %= M; 
        }

        // observe that there will always be an optimal choice of x equal to one of the numbers
        sort(a.begin(), a.end());

        // for (int i = 1; i <= N; i++)
        //     cout << a[i] << ' ';
        // cout << '\n';

        vector<ll> ps(N+1);
        for (int i = 1; i <= N; i++)
            ps[i] = ps[i-1] + a[i];
        
        ll ans = LLONG_MAX;
        
        //alternative solution: we know the ideal choice of x will have half numbers incremented and half decremented
        //                      we can double the array, and work from indices N/2 to 3N/2
        for (int i = 1; i <= N; i++)
        {
            if (a[i] <= M/2)
            {
                int j = upper_bound(a.begin()+1, a.end(), a[i]+M/2) - a.begin()-1;
                ll val = (ll)i*a[i] - ps[i] 
                        + (ps[j]-ps[i]) - (ll)(j-i)*a[i]
                        + (ll)a[i]*(N-j) + (ll)(N-j)*M - (ps[N]-ps[j]);
                ans = min(ans, val);
            }
            else
            {
                int j = lower_bound(a.begin()+1, a.end(), a[i]-M/2) - a.begin();
                ll val = (ps[N]-ps[i]) - (ll)(N-i)*a[i] 
                        + (ll)(i-j+1)*a[i] - (ps[i]-ps[j-1]) 
                        + (ll)(j-1)*(M-a[i]) + ps[j-1];
                ans = min(ans, val);
            }
        }
        
        cout << ans << '\n';
    }
}