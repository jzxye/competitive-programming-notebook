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
        string s; cin >> s;

        if (n % 2 == 0) //do not delete
        {
            int odd_count[26]{};
            int even_count[26]{};
            for (int i = 0; i < n; i += 2)
            {
                odd_count[s[i]-'a']++;
                even_count[s[i+1]-'a']++;
            }
            
            int odd = 0;
            int even = 0;
            for (int i = 0; i < 26; i++)
            {
                odd = max(odd, odd_count[i]);
                even = max(even, even_count[i]);
            }
            cout << n - odd - even << '\n';
        }
        else //we must delete one
        {
            vector<vector<int>> ps_odd(n+1); ps_odd[0] = vector<int>(26, 0);
            vector<vector<int>> ps_even(n+1); ps_even[0] = vector<int>(26, 0);
            
            for (int i = 1; i <= n; i++)
            {
                ps_odd[i] = ps_odd[i-1];
                ps_even[i] = ps_even[i-1];
                if ((i-1)%2 == 0)
                    ps_even[i][s[i-1]-'a']++;
                else
                    ps_odd[i][s[i-1]-'a']++;
            }

            vector<vector<int>> ss_odd(n+1); ss_odd[n] = vector<int>(26, 0);
            vector<vector<int>> ss_even(n+1); ss_even[n] = vector<int>(26, 0);
            for (int i = n-1; i >= 0; i--)
            {
                ss_odd[i] = ss_odd[i+1];
                ss_even[i] = ss_even[i+1];
                if (i%2 == 0)
                    ss_even[i][s[i]-'a']++;
                else
                    ss_odd[i][s[i]-'a']++;
            }
            
            int ans = INT_MAX;
            for(int i = 0; i < n; i++)
            {
                int odd_count[26]{};
                int even_count[26]{};
                for (int j = 0; j < 26; j++)
                {
                    odd_count[j] += ps_odd[i][j] + ss_even[i+1][j];
                    even_count[j] += ps_even[i][j] + ss_odd[i+1][j];
                }

                // DEBUG: error was in ps initialization, i%2 --> (i-1)%2
                // cout << "trial: " << i << '\n';
                // for (int j = 0; j < 26; j++)
                // {
                //     cout << (char)('a'+j) << ':' << odd_count[j] << ' ';
                // }
                // cout << '\n';
                // for (int j = 0; j < 26; j++)
                // {
                //     cout << (char)('a'+j) << ':' << even_count[j] << ' ';
                // }
                // cout << "\n\n";

                int odd = 0;
                int even = 0;
                for (int j = 0; j < 26; j++)
                {
                    odd = max(odd, odd_count[j]);
                    even = max(even, even_count[j]);
                }

                ans = min(ans, n-odd-even);
            }
            cout << ans << '\n';
        }
    }
}