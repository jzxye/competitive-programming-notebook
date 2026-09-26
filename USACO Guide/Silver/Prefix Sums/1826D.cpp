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
        vector<int> b(n); 
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> pi(n); pi[0] = 0;
        vector<int> si(n); si[n-1] = n-1;
        for (int i = 1; i < n; i++)
            pi[i] = b[i]+i >= b[pi[i-1]]+pi[i-1] ? i : pi[i-1];

        for (int i = n-2; i >= 0; i--)
            si[i] = b[i]-i >= b[si[i+1]]-si[i+1] ? i : si[i+1];


        int ans = 0;
        for (int mid = 1; mid < n-1; mid++)
            ans = max(ans, b[pi[mid-1]] + b[mid] + b[si[mid+1]] - (si[mid+1]-pi[mid-1]));

        cout << ans << '\n';
    }
}