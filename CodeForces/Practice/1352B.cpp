#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        
        if (n%2 == 0)
        {
            if (k%2 == 0)
            {
                if (n < k)
                    cout << "NO" << '\n';
                else
                {
                    cout << "YES" << '\n';
                    for(int i = 1; i < k; i++) cout << 1 << ' ';
                    cout << n-k+1 << '\n';
                }
            }
            else
            {
                if (n < 2*k)
                    cout << "NO" << '\n';
                else
                {
                    cout << "YES" << '\n';
                    for (int i = 1; i < k; i++) cout << 2 << ' ';
                    cout << n-2*(k-1) << '\n';
                }
            }
        }
        else 
        {
            if(k%2==0 || n < k)
                cout << "NO" << '\n';
            else 
            {
                cout << "YES" << '\n';
                for(int i = 1; i < k; i++) cout << 1 << ' ';
                cout << n-k+1 << '\n';
            }
        }
    }
}