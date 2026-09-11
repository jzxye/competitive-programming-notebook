#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n); for (int &ai : a) cin >> ai;

        unordered_map<int,int> remainder_count;
        for (int &ai : a)
            if(ai%k != 0)
                remainder_count[ai%k]++;

        int freq = 1;
        int m = k+1;
        for (auto p : remainder_count)
        {
            if (p.second >= freq)
            {
                if(p.second == freq)
                    m = min(m, p.first);
                else
                    m = p.first;
                freq = p.second;
            }
        }  
        cout << (ll)k * (freq-1) + (k-m+1) << '\n';
    }
}