#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int XMAX = 1000000;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    unordered_set<ll> primes; 
    for (ll num = 2; num <= XMAX; num++)
    {
        ll primeThres = floor(sqrt(num));
        bool prime = true;
        for (int div = 2; div <= primeThres; div++)
        {
            if (num % div == 0) 
            {
                prime = false;
                break;
            }
        }
        if (prime) primes.insert(num);
    }

    int n; cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        ll x; cin >> x;

        ll root = floor(sqrt(x));

        if (root*root == x && primes.count(root))
            cout << "YES" << '\n';
        else 
            cout << "NO" << '\n';
    }
    //vector<int> x(n); for (int &xi : x) cin >> xi;




}