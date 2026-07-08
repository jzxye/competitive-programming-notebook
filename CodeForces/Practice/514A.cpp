#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char first; cin >> first;
    if (first == '9' || first -'0' < 5)
        cout << first;
    else
        cout << (char)('9'-first+'0');

    char dig;
    while (cin >> dig)
    {
        if (dig -'0' < 5)
            cout << dig;
        else
            cout << (char)('9'-dig+'0');
    }
    cout << '\n';

}