#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int x = 0;
    for (int i = 0; i < n; i++)
    {
        string op; cin >> op;
        if (op[1] == '+')
            x++;
        else 
            x--;
    }
    cout << x << '\n';
}