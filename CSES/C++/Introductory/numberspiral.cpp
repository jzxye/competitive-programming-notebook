#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int y, x; cin >> y >> x;

        int layer = max(x,y);

        // ll num = (ll)layer*layer;

        // if(layer % 2 == 0)
        // {
        //     if (y == layer)
        //         cout << num - (x-1) << '\n';
        //     else
        //         cout << num - (2*layer-1) + y << '\n';
        // }
        // else
        // {
        //     if (x == layer)
        //         cout << num - (y-1) << '\n';
        //     else
        //         cout << num - (2*layer-1) + x << '\n';
        // }

        //M1: Count from the last layer
        // ll answer = (ll)(layer-1)*(layer-1);
        // if (layer % 2 == 0)
        //     answer += y + layer-x;
        // else 
        //     answer += x + layer-y;
        // cout << answer << '\n';

        //M2: Count backwards from layer^2
        ll answer = (ll)layer*layer;
        if (layer % 2 == 0)
            answer -= x-1 + layer-y;
        else 
            answer -= y-1 + layer-x;
        cout << answer << '\n';
    }
}