#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int ones = 0;
    vector<int> a(n); 
    for (int &ai : a) 
    {
        cin >> ai; 
        ones += ai;
    }

    // vector<int> ps(n+1); ps[0] = 0;
    // for(int i = 1; i <= n; i++)
    // {
    //     if(a[i-1]) ps[i] = ps[i-1]-1;
    //     else ps[i] = ps[i-1]+1;
    // }

    // int gain = INT_MIN;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = i; j <= n; j++)
    //         gain = max(gain, ps[j] - ps[i-1]);
    // }

    // cout << ones + gain << '\n';


    // The above solution is O(n^2) using prefix sums but I completely overlooked the 
    // dynamic programming solution "maximum subsequence sum"

    vector<int> b(n); 
    for (int i = 0; i < n; i++)
        b[i] = a[i] ? -1 : 1;
    
    vector<int> gain(n+1); 
    for (int i = 1; i <= n; i++)
    {
        gain[i] = max(b[i-1], gain[i-1] + b[i-1]);
    }

    int max_gain = INT_MIN; 
    for (int i = 1; i <= n; i++)
        max_gain = max(max_gain, gain[i]);

    cout << ones + max_gain << '\n';
}