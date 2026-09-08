#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; ll k; cin >> n >> k;
    vector<int> a(n); for (int &ai : a) cin >> ai;

    sort(a.begin(), a.end());
    
    //observation: never beneficial to increment below the halfway mark

    int curr = a[n/2];
    for (int i = n/2; i < n; i++)
    {
        int width = i-n/2;
        if (k >= (ll)width * (a[i]-curr))
        {
            k -= (ll)width * (a[i]-curr);
            curr = a[i];
        }
        else
        {
            curr += k / width;
            k -= k / width * width;
            break;
        }
    }
    curr += k / (n/2+1);
    cout << curr << '\n';
}