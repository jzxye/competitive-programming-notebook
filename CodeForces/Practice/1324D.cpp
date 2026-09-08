#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for (int &ai: a) cin >> ai;
    vector<int> b(n); for (int &bi : b) cin >> bi;

    // a_i-b_i > b_j-a_j
    // a_i-b_i + (a_j-b_j) > 0

    vector<int> diff(n); for (int i = 0; i < n; i++) diff[i] = a[i]-b[i];
    // sort(diff.begin(), diff.end());

    // ll good = 0;
    // int i = 0;
    // int j = n-1;

    // while (i < j)
    // {
    //     if(diff[i] + diff[j] <= 0)
    //         i++;
    //     else
    //         break;
    // }
    // while (i < j)
    // {
    //     while (i < j && diff[i] + diff[j] > 0)
    //         j--;

    //     good += n - (j+1);
    //     i++;
    // }
    // for (; i < n; i++)
    // {
    //     good += n - (i+1);
    // }

    // PROPER IMPLEMENTATION
    sort(diff.begin(), diff.end());
    ll good = 0;
    int j = n - 1;
    for (int i = 0; i < n; i++) {
        while (j > i && diff[i] + diff[j] > 0) j--;
        good += n - 1 - max(j, i);
    }

    cout << good << '\n';
}