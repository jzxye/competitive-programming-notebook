#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin >> n >> m;
    
    if (n >= m) cout << n-m << '\n';
    else // n < m
    {
        int red = ceil(log2((m+n-1)/n));
        int mult = 1<<red;
        
        int curr = n;
        int clicks = red;
        while (mult != 0)
        {
            // while ((curr-1) * mult >= m)
            // {
            //     curr--;
            //     clicks++;
            // }
            int blue = (curr * mult - m)/mult;
            curr -= blue;
            clicks += blue;

            mult /= 2;
            curr *= 2; 
        }

        cout << clicks << '\n';
    }
}