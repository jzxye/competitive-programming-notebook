#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //Honeycake
    ll w, h, d; cin >> w >> h >> d;
    ll n; cin >> n;
    
    if (((w%n) * (h%n))%n * (d%n) % n != 0)
    {
        cout << -1 << '\n';
        return 0;
    }
    
    ll wp = gcd(n, w);
    n /= wp;
    ll hp = gcd(n, h);
    n /= hp;
    ll dp = gcd(n, d);
    
    wp--;
    hp--;
    dp--;
    cout << wp << ' ' << hp << ' ' << dp << ' ' << '\n';
    return 0;
}