#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> even;
    vector<int> odd;
    for (int i = 1; i <= n; i++)
    {
        int num; cin >> num;
        if (num%2 == 0) even.push_back(i);
        else odd.push_back(i);
    }
    if (even.size() == 1) cout << even[0] << '\n';
    else cout << odd[0] << '\n';
}