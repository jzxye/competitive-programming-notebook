#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> b(n); for (int &bi : b) cin >> bi;

    sort(b.begin(), b.end()); //sorting is faster implementation but not necessary

    int diff = b[n-1] - b[0];

    ll i = count(b.begin(), b.end(), b[0]);
    ll j = count(b.begin(), b.end(), b[n-1]);

    ll pairs = 0;
    if (b[0] == b[n-1]) pairs =(ll)n*(n-1)/2;
    else pairs = i * j;

    cout << diff << ' ' << pairs << '\n';
}