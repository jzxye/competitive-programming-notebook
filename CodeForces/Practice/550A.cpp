#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    int ab_i = -1;
    for (int i = 0; i < s.size()-1; i++)
    {
        if (s[i] == 'A' && s[i+1] == 'B')
        {
            ab_i = i;
            break;
        }
    }

    int ab_f = -1;
    for (int i = s.size()-2; i >= 0; i--)
    {
        if (s[i] == 'A' && s[i+1] == 'B')
        {
            ab_f = i;
            break;
        }
    }

    int ba_i = -1;
    for (int i = 0; i < s.size()-1; i++)
    {
        if (s[i] == 'B' && s[i+1] == 'A')
        {
            ba_i = i;
            break;
        }
    }

    int ba_f = -1;
    for (int i = s.size()-2; i >= 0; i--)
    {
        if (s[i] == 'B' && s[i+1] == 'A')
        {
            ba_f = i;
            break;
        }
    }

    // cout << ab_i << ' ' << ab_f << ' ' << ba_i << ' ' << ba_f << '\n';

    if (ab_i == -1 || ba_i == -1)
        cout << "NO" << '\n';
    else
    {
        if (abs(ab_i-ba_f) != 1 || abs(ab_f-ba_i) != 1)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

}