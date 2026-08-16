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

        ll sum = 0;
        bool positive = a[0] > 0;
        int i, j; i = j = 0;
        while (j < n)
        {
            while (j<n && (a[j] > 0) == positive) j++;
            sort(a.begin()+i, a.begin()+j);

            // for (int &ai : a) cout << ai << ' ';
            // cout << '\n';

            sum += a[j-1];

            i = j;
            positive = !positive;
        }
        cout << sum << '\n';
        
    }
}