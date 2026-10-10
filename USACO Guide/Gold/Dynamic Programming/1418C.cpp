#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n+1); 
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        
        vector<int> M1(n+1); //end of my turn
        vector<int> M2(n+1); //end of friend's turn

        M1[0] = 0; M1[1] = a[1]; 
        M2[0] = INF; M2[1] = a[1]; 

        for (int i = 2; i <= n; i++){
            M1[i] = min(M2[i-1], M2[i-2]);  
            M2[i] = min(M1[i-1] + a[i], M1[i-2] + a[i-1] + a[i]);
        }

        int ans = min(M1[n], M2[n]);
        cout << ans << '\n';
    }
}