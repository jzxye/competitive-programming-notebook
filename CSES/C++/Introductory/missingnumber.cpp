#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    ll sum = 0;
    for (int i = 1; i < n; i++)
    {
        int x; cin >> x;
        sum += x;
    }
    int missing = (ll)n*(n+1)/2 - sum;
    cout << missing << '\n';
}