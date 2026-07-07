#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> a(n); for (int &ai : a) cin >> ai;

        vector<int> count;
        int num = 1;
        for (int i = 1; i < n; i++)
        {
            num++;
            if(a[i] != a[i-1])
            {
                count.push_back(num);
                num = 0;
            }
        }
        count.push_back(num);
        sort(count.begin(), count.end());
        int distinct = count.size();


        //possible[n][k] = number of possible arrays with n distinct elements of length k
        vector<vector<int>> possible(distinct+1, vector<int>(k+1, 0)); 

        int elements = n;
        for (int i = 0; i < distinct; i++)
        {
            if (i > 0 && count[i] == count[i-1]) 
                continue;
            elements -= (distinct-i)*(count[i]-1);
            possible[distinct-i][elements] = 1;
            elements -= distinct-i;
        }

        for (int l = 1; l <= k; l++)
        {
            for (int m = 1; m <= distinct; m++)
                if(l-m >= 0)
                    possible[m][l] += possible[m][l-m];
        }

        int answer = 0;
        for (int i = 1; i <= distinct; i++)
            answer += possible[i][k];

        cout << answer << '\n';
    }
}