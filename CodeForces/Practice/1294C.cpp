#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //TODO: polish up implementation

    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;

        bool possible = true;
        set<int> factors;
        for (int i = 0; i < 2; i++)
        {
            int factor = 1;
            for(int k = 2; k < sqrt(n); k++)
            {
                if (n % k == 0 && !factors.count(k)) 
                {
                    factor = k;
                    factors.insert(k);
                    break;
                }
            }

            n /= factor;

            if (factor == 1) 
            {
                possible = false;
                break;
            }
        }
        factors.insert(n);
        if(n == 1 || factors.size() < 3) possible = false;

        if (possible)
        {
            cout << "YES" << '\n';

            bool first = true;
            for (int k : factors)
            {
                if (!first)
                {
                    cout << ' ' << k;
                }
                else
                {
                    cout << k;
                    first = false;
                }
            }
            cout << '\n';
        }
        else
            cout << "NO" << '\n';
    }
}