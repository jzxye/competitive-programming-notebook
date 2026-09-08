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

        int ends = 0; ends = a[0] + a[n-1];
        int easy = 0;
        int hard = 0;
        for (int &ai : a)
            if (ai == 0) 
                easy++;
            else
                hard++;
        
        if (ends == 0)
        {
            cout << 0 << '\n';
        }
        else if (ends == 1)
        {
            if(easy -1 >= 1)
                cout << 1 << '\n';
            else 
                cout << -1 << '\n';
        }
        else 
        {
            if (easy >= 2)
            {
                cout << 2 << '\n';
            }
            else
                cout << -1 << '\n';
        }
            

    }
}