#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int SUBSTR_COUNT = 1000;
const int MAX_DIGITS = 100;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n; cin >> n;

    bool contains[SUBSTR_COUNT]{};
    //we want substring 008, 016, ..., 992

    int digs = n.size();
    for (int i = 0; i < digs; i++)
    {
        int d = n[i] - '0';

        for (int j = 99; j >= 1; j--)
            if(contains[j])
                contains[10*j+d] = true;

        contains[d] = true;
    }

    for(int i = 0; i < 1000; i += 8)
    {
        if (contains[i])
        {
            cout << "YES" << '\n';
            cout << i << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    return 0;
}