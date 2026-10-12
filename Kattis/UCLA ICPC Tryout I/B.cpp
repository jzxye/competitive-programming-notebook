#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_SHARES = 100000;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int d; cin >> d;
    vector<int> p(d+1);
    for (int i = 1; i <= d; i++)
        cin >> p[i];

    ll money = 100;
    ll shares = 0;
    for (int i = 1; i < d; i++){
        if(p[i+1] < p[i]){
            money += shares * p[i];
            shares = 0;
        }
        else if (p[i+1] > p[i]){
            if (shares + money/p[i] > MAX_SHARES){
                money -= (MAX_SHARES - shares) * p[i];
                shares = MAX_SHARES;
            }else{
                shares += money / p[i];
                money %= p[i];
            }
        }
    }
    money += shares * p[d];

    cout << money << '\n';
}