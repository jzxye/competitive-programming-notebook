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
        string s; cin >> s;
        int one = 0;
        int zero = 0;
        int firstZero = -1;
        int lastZero = -1;
        int firstOne = -1;
        int lastOne = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0') 
            {
                zero++;
                lastZero = i;
                if (firstZero == -1) firstZero = i;

            }
            else
            {
                one++;
                lastOne = i;
                if (firstOne == -1) firstOne = i;
            } 

        }
        if (one == 0 || zero == 0)
            cout << 1 << '\n';
        else if (lastOne < firstZero || lastZero < firstOne)
            cout << 2 << '\n';
        else
            cout << 1 << '\n';
    }
}