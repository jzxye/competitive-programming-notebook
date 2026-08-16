#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int count = 0;
    while (n > 0)
    {
        count += n/5;
        n /= 5;
    }
    cout << count << '\n';

}