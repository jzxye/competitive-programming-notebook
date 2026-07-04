#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l; cin >> n >> l;
    vector<double> a(n); for (auto &ai : a) cin >> ai;
    sort(a.begin(), a.end());

    double d = max(a[0], l-a[n-1]);
    for (int i = 1; i < n; i++)
    {
        d = max(d, (a[i]-a[i-1])/2);
    }

    printf("%.10f\n", d);

}