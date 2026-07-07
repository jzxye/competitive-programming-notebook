#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n); for (int &ai : a) cin >> ai;

        vector<int> ones(n); ones[0] = a[0] == 1;
        vector<int> twos(n); twos[0] = a[0] == 2;
        vector<int> threes(n); threes[0] = a[0] == 3;
        for (int i = 1; i < n; i++)
        {
            ones[i] = ones[i-1] + (a[i] == 1);
            twos[i] = twos[i-1] + (a[i] == 2);
            threes[i] = threes[i-1] + (a[i] == 3);
        }

        vector<int> maxdelta(n); 
        for (int i = n-2; i >= 1; i--)
        {   
            maxdelta[i] = ones[i] + twos[i] - threes[i];
            if (i < n-2)
                maxdelta[i] = max(maxdelta[i], maxdelta[i+1]);
        }


        bool valid = false;
        for (int i = 0; i < n-2; i++)
        {
            if (ones[i] >= twos[i] + threes[i] && maxdelta[i+1]-(ones[i]+twos[i]-threes[i]) >= 0)
            {
                valid = true;
                break;
            }
        }

        if (valid)
            cout << "YES" << '\n';
        else 
            cout << "NO" << '\n';

        /*int idx1 = -1;
        for (int i = 0; i < n; i++)
        {
            if(ones[i] >= twos[i] + threes[i])
            {
                idx1 = i;
                break;
            }
        }
        if (idx1 == -1) 
        {
            cout << "NO" << '\n';
            continue;
        }

        int idx2 = -1;
        for (int i = idx1+1; i < n; i++)
        {
            if (threes[i]-threes[idx1] <= twos[i]-twos[idx1] + ones[i]-ones[idx1])
            {
                idx2 = i;
                break;
            }
        }
        if (idx2 == -1 || idx2 == n-1) 
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
            */
    }
}