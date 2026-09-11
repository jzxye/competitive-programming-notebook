#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d; cin >> n >> d;
    vector<pair<int,int>> zipped(n); 

    for (int i = 0; i < n; i++)
    {
        int mi, si;
        cin >> mi >> si;
        zipped[i] = {mi, si};
    }
    sort(zipped.begin(), zipped.end());

    int l = 0;
    int r = 0;
    ll ff = 0; //friendship factor

    ll curr = 0;
    while (r < n)
    {
        while(r < n && zipped[r].first - zipped[l].first < d)
        {
            curr += zipped[r].second;
            r++;
        }
        ff = max(ff, curr);
        curr -= zipped[l].second;
        l++;
    }
    cout << ff << '\n';
}