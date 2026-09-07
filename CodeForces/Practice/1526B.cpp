#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int x; cin >> x;

        //observation: once we have a number in a residue class (mod 11) we can form all greater numbers in that class
        //111 = 1 mod 11, so the smallest numbers in each residue class are: 
        //0: 0
        //1: 111
        //2: 222
        //3: 333
        //...
        //9: 999
        //10: 1110
        //all numbers >= 1110 can be formed

        int smallest[] = {0,111,222,333,444,555,666,777,888,999,1110};
        if (x >= smallest[x%11])
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}