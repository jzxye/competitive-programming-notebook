//
//  sheikahtowers.cpp
//  CodeSprint2026
//
//  Created by Joshua Ye on 5/9/26.
//

#if 0
#include <iostream>
using namespace std;

int NMAX = 200000;
int MMAX = 200000;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n,m,h,s; cin >> n >> m >> h >> s;
        int a[NMAX+1]; a[0] = 0; for (int i = 1; i <= n; i++) cin >> a[i];
        int b[MMAX+1]; b[0] = 0; for (int i = 1; i <= m; i++) cin >> b[i];
        
        bool climbable = true;
        int i = 0, j = 0;
        for(;;)
        {
            int ii = i;
            int jj = j;
            
            while (i < n && a[i+1]-a[i] <= s) i++;
            while (j < m && b[j+1]-b[j] <= s) j++;
            
            
            if (h-a[i] <= s || h-b[j] <= s) break;

            if (i == ii && j == jj) //stuck
            {
                climbable = false;
                break;
            }
            
            //paraglider
            if(a[i] > b[j])
                while(j < m && b[j+1] <= a[i]) j++;
            else
                while(i < n && a[i+1] <= b[j]) i++;
        }
        cout << (climbable ? "YES" : "NO") << '\n';
    }
    return 0;
}
#endif
