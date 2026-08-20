#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// int n;
// vector<int> val;

// int sum(int k)
// {
//     int s = 0;
//     while(k >= 1)
//     {
//         s += val[k];
//         k -= k&-k;
//     }
//     return s;
// }
// void add(int k, int s)
// {
//     while (k <= n)
//     {
//         val[k] += s;
//         k += k&-k;
//     }
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<int> a(n); for (int &ai : a) cin >> ai; 

    // val.resize(n+2);
    vector<int> val(n+1);
    for (int i = 0; i < q; i++)
    {
        int l,r; cin >> l >> r;
        l--;
        r--;

        val[l]++;
        val[r+1]--;
        // add(l ,1); 
        // add(r+1, -1);
        // for (int ii = l; ii <= r; ii++)
        //     count[ii]++;
    }

    int v = 0;
    vector<int> count(n);
    for (int i = 0; i < n; i++)
    {
        v += val[i];
        count[i] = v;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     count[i] = sum(i+1);
    // }

    sort(a.begin(), a.end());
    sort(count.begin(), count.end());

    ll M = 0;
    for (int i = 0; i < n; i++)
        M += (ll)a[i] * count[i];

    cout << M << '\n';

}

