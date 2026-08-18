#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int NMAX = 100000;
const int AMAX = 100000;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for (int &ai : a) cin >> ai;
    
    int count[AMAX+1]{};
    for (int &ai : a)
        count[ai]++;
    
    vector<ll> M(AMAX+1); M[0] = 0; M[1] = count[1];
    for (int i = 2; i <= AMAX; i++)
    {
        M[i] = max(M[i-1], M[i-2] + (ll)count[i]*i);
    }

    cout << M[AMAX] << '\n';
}