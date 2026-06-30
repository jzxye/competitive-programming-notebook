#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxLength = 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        if (s.length() <= maxLength)
            cout << s << '\n';
        else
        {
            cout << s[0];
            cout << s.length()-2;
            cout << s[s.length()-1] << '\n';
        }
    }
}