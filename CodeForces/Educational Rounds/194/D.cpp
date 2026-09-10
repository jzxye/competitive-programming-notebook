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
        s = ' ' + s;

        if (s[1] == '0')
        {
            cout << -1 << '\n';
            continue;
        }
    
        //no consecutive zeros
        bool invalid = false;
        for (int i = 1; i < n; i++)
        {
            if(s[i] == '0' && s[i+1] == '0')
            {
                cout << -1 << '\n';
                invalid = true;
                break;
            }
        }
        if (invalid)
            continue;

        //observation: |prefix| can only be 0, 1, 2
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        vector<int> M1(n+1); M1[0] = 0;
        vector<int> M2(n+1); M2[0] = 0;
        vector<int> M3(n+1); M3[0] = 0;
        
        for (int i = 1; i <= n; i++)
        {
            if (s[i]== '+')
            {
                if(p1 == 1)
                    M1[i] = min(max(M2[i-1], abs(1-p2)), 
                                max(M3[i-1], abs(1-p3)));
                else
                    M1[i] = min(min(max(M1[i-1], abs(1-p1)), 
                                    max(M2[i-1], abs(1-p2))), 
                                    max(M3[i-1], abs(1-p3)));
                
                if (p2 == 2)
                    M2[i] = min(max(M1[i-1], abs(2-p1)), 
                                max(M3[i-1], abs(2-p3)));
                else 
                    M2[i] = min(min(max(M1[i-1], abs(2-p1)), 
                                    max(M2[i-1], abs(2-p2))), 
                                    max(M3[i-1], abs(2-p3)));

                if (p3 == 3)
                    M3[i] = min(max(M1[i-1], abs(3-p1)), max(M2[i-1], abs(3-p2)));
                else 
                    M3[i] = min(min(max(M1[i-1], abs(3-p1)), max(M2[i-1], abs(3-p2))), max(M3[i-1], abs(3-p3)));
                p1 = 1;
                p2 = 2;
                p3 = 3;
            }
            else if (s[i] == '-')
            {
                if(p1 == -1)
                    M1[i] = min(max(M2[i-1], abs(-1-p2)), max(M3[i-1], abs(-1-p3)));
                else
                    M1[i] = min(min(max(M1[i-1], abs(-1-p1)), max(M2[i-1], abs(-1-p2))), max(M3[i-1], abs(-1-p3)));
                
                if (p2 == -2)
                    M2[i] = min(max(M1[i-1], abs(-2-p1)), max(M3[i-1], abs(-2-p3)));
                else 
                    M2[i] = min(min(max(M1[i-1], abs(-2-p1)), max(M2[i-1], abs(-2-p2))), max(M3[i-1], abs(-2-p3)));

                if (p3 == -3)
                    M3[i] = min(max(M1[i-1], abs(-3-p1)), max(M2[i-1], abs(-3-p2)));
                else 
                    M3[i] = min(min(max(M1[i-1], abs(-3-p1)), max(M2[i-1], abs(-3-p2))), max(M3[i-1], abs(-3-p3)));

                p1 = -1;
                p2 = -2;
                p3 = -3;
            }
            else if (s[i] == '0')
            {
                M1[i] = M2[i] = M3[i] = min(min(max(M1[i-1],abs(p1)), max(M2[i-1],abs(p2))), max(M3[i-1], abs(p3)));
                p1 = p2 = p3 = 0;
            }
        }

        int ans = min(min(M1[n], M2[n]), M3[n]);
        cout << ans << '\n';
    }
}