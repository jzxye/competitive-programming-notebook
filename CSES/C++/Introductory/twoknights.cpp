#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    ll invalid[100001]; invalid[1] = 0;
    for (int k = 2; k <= n; k++)
    {
        invalid[k] = invalid[k-1];

        if (3 <= k && 2 <= k)
            invalid[k]+=2;

        for (int i = 2; i <= k; i++)
        {
            int j = 1; 
            if(i+2 <= k && j+1 <= k)
                invalid[k]+=2;
            if(i-2 >= 1 && j+1 <= k)
            {
                if(i == 3)
                    invalid[k]++;
                else
                    invalid[k]+=2;
            }
            if(i+1 <= k && j+2 <= k)
                invalid[k]+=2;
            if(i-1 >= 1 && j+2 <= k)
            {
                if(i == 2)
                    invalid[k]++;
                else
                    invalid[k]+=2;
            }
        }

    }

    for (int k = 1; k <= n; k++)
        cout << (ll)k*k*(k*k-1)/2 - invalid[k] << '\n';
}