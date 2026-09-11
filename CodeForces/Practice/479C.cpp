#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int,int>> zipped(n);

    for (int i = 0; i < n; i++)
    {
        int ai, bi; cin >> ai >> bi;
        zipped[i] = {ai,bi};
    }
    sort(zipped.begin(), zipped.end());

    int day = 0;
    for(int i = 0; i < n; i++)
    {
        int ai = zipped[i].first;
        int bi = zipped[i].second;

        if (bi >= day)
            day = bi;
        else
            day = ai;
    }

    cout << day << '\n';

}