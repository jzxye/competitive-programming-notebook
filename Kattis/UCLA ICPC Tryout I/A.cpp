#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2; cin >> n1 >> n2;

    // int ans;
    // if(n1 > n2){
    //     if (n1 - n2 <= 360 - (n1-n2))
    //         ans = -(n1-n2);
    //     else
    //         ans = (360-(n1-n2));
    // }else{
    //     if (n2 - n1 <= 360 - (n2-n1))
    //         ans = n2-n1;
    //     else
    //         ans = -(360-(n2-n1));
    // }
    // cout << ans << '\n';

    int ans = INT_MAX;
    for (int spin = -179; spin <= 180; spin++){
        if (((n1 + spin)+360)%360 == n2) {
            cout << spin << '\n';
            break;
        }
        // if (abs(spin) < abs(ans)){
        //     ans = spin;
        // }
    }
    // cout << ans << '\n';
}