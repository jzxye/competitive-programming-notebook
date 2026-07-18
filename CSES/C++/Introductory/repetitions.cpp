#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int longest = 1;
    int curr = 1;
    char last; cin >> last;
    char c;
    while (cin >> c)
    {
        if (c == last) curr++;
        else curr = 1;
        last = c;
        longest = max(longest, curr);
    }
    cout << longest << '\n';
}