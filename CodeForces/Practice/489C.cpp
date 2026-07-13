#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, s; cin >> m >> s;

    string small, large;

    int digs = m;
    int sum = s;
    while (digs--)
    {
        int next = min(9, sum);
        sum -= next;
        large += '0' + next;

        // if(digs != 0 && next == 0) 
        // {
        //     large = "-1";
        //     break;
        // }
    }
    if (sum != 0 || (m > 1 && large[0] == '0'))
        large = "-1";

    digs = m;
    sum = s;
    int lastNonZero = 0;
    while(digs--)
    {
        int next = min(9, sum);
        sum -= next;
        small = (char)('0' + next) + small;

        if (next != 0) lastNonZero = digs;
    }
    if (m > 1 && small[0] == '0') 
    {
        small[0] = '1';
        small[lastNonZero] = small[lastNonZero] - 1;
    }
    if (sum != 0 || (m > 1 && small[0] == '0'))
        small = "-1";

    cout << small << ' ' << large << '\n';
}