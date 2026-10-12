#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, p; cin >> n >> p;

    //int l = 0; int r = LLONG_MAX;
    ll x = 1;
    long double ans =  (long double)p/(n+1); //base case: x = 1
    long double mult = (double)((x+1)*(n+x-p+1))/((x)*(n+x+1));
    // cout << ans << '\n';
    while(mult >= 1){
        ans *= mult;
        x++;
        mult = (long double)((x+1)*(n+x-p+1))/((x)*(n+x+1));
    }

    // ans = (long double)p * x/(n+x);
    // for (int i = 1; i < min(x,p+1); i++){
    //     ans *= (long double)(n+1+i-p)/(n+i);
    // }
    
    cout << fixed << setprecision(12) << ans << '\n';

    // while
    // while (l <= r){
    //     int x = (l+r)/2;
    //     double val = p * (x/(n+x));
    //     for (int i = 1; i <= p-1; i++){
    //         val *= (n+1-i)/(n+x-i);
    //     }
    //     if (val >= ans){
    //         ans = val;

    //     }
    // }
    // cout << ans << '\n';
}