#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        count *= 2;
        count %= 1000000007;
    }
    cout << count << '\n';
}