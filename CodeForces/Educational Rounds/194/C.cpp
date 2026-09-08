#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int x,y; cin >> x >> y;

        // y -> highest power of 2 <= x+y
        int sum = x+y;
        int ops = 0;

        while ((x & y) != 0) 
        {
            int n = 1;
            int digs = 1;
            while (n<<1 <= (x & y))
            {
                n <<= 1;
                digs++;
            }
            
            int k = min(x-n+1, (n<<1)-(y&((1<<digs) - 1)));
            
            ops+=k;
            x-=k;
            y+=k;
            // cout << x << ' ' << y << ' ' << ops << '\n';
        }
        // int n = 0;
        // while (n < 32 && (1<<(n+1)) <= x+y) n++;
        // int p2 = 1<<n;

        // int operations = max(0, p2-y);
        cout << sum << ' ' << ops << '\n';
    }
}