#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        // vector<int> a; 
        // for (int i = 1; i <= n; i++) a.push_back(i);

        vector<int> b; 
        b.push_back(n);
        for (int i = 1; i < n; i++) b.push_back(i);

        for (int i = 1; i <= n; i++) 
            cout << i << ' ';
        
        for (int i = 1; i <= n; i++) 
            cout << i << ' ';
        
        for (int i = 0; i < n; i++) 
            cout << b[i] << ' ';

        for (int i = 1; i < n; i++)
            cout << i << ' ';
        cout << n << '\n';
        
    }
}