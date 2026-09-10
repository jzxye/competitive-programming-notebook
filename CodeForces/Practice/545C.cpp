#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> x(n+1);
    vector<int> h(n+1); 
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> h[i];

    vector<int> p(n+1);
    vector<int> q(n+1);
    for (int i = 1; i <= n; i++)
    {
        int ii = upper_bound(x.begin(), x.end(), x[i] + h[i]) - x.begin();
        if (ii <= n) p[ii] = i;

        q[i] = lower_bound(x.begin()+1, x.end(), x[i]-h[i]) - x.begin() - 1;
    }
    
    vector<int> R(n+1); R[0] = 0;
    vector<int> L(n+1); L[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < n && x[i]+h[i] >= x[i+1])
            R[i] = max(L[i-1], R[p[i]]);
        else
            R[i] = 1 + max(L[i-1], R[p[i]]);

        L[i] = max(L[i-1], R[p[i]]);
        if (i == 1 || x[i]-h[i] > x[i-1])
        {
            int iii = x[q[i]] + h[q[i]] < x[i]-h[i] ? q[i] : p[q[i]];
            L[i] = max(L[i], 1 + max(L[q[i]], R[iii]));
        }

        //let p(i) denote the greatest index such that felling right does not hit tree i
        //let q(i) denote the greatest index that does not get hit by i falling left
        //case 1: right = 1 + max(L[i-1], R[p(i)]).    (if right is possible)
        //case 2: left = 1 + max(L[q(i)], R[p(q(i))])  (if left is possible)
        //case 3: none = max( L[i-1], R[p(i)])
    }


    //in hindsight, there is a much simpler greedy solution: fell left if possible, else fell right if possible

    cout << R[n] << '\n';

}