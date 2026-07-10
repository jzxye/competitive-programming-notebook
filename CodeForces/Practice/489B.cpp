#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for (int &ai : a) cin >> ai;
    sort(a.begin(), a.end());

    int m; cin >> m;
    vector<int> b(m); for (int &bi : b) cin >> bi;
    sort(b.begin(), b.end());

    int i = 0;
    int j = 0;
    int count = 0;
    while(i < n && j < m)
    {
        if(abs(a[i] - b[j]) <= 1)
        {
            count++;
            i++;
            j++;
        }
        else if(a[i] < b[j])
            i++;
        else 
            j++;
    }
    cout << count << '\n';
}