#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n, x, y, z; cin >> n >> x >> y >> z;

        int t1 = 0;
        int temp = n;
        while(temp > 0)
        {
            temp -= x;
            if (t1 >= z)
                temp -= 10*y;
            t1++;
        }

        int t2 = 0;
        temp = n;
        while (temp > 0)
        {
            temp -= x;
            temp -= y;
            t2++;
        }

        cout << min(t1, t2) << '\n';
    }
}