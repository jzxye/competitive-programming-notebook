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
        vector<int> a(n); for (int &ai : a) cin >> ai;

        //a_j - a_i = j - i  <=>  a_j-j = a_i-i
        for (int i = 1; i <= n; i++)
            a[i-1] -= i;

        unordered_map<int, int> count; for (int &ai : a) count[ai]++; 

        ll pairs = 0;
        for (auto pair : count) 
            pairs += (ll)pair.second * (pair.second-1) /2;

        cout << pairs << '\n';

        
    }
}