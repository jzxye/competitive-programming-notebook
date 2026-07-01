//
//  sneakylink.cpp
//  CodeSprint2026
//
//  Created by Joshua Ye on 5/9/26.
//
#if 0
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int NMAX = 200000;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; int c; cin >> n >> c;
        int a[NMAX]; for (int i = 0; i < n; i++) cin >> a[i];
        
        sort(a, a+n);
        
        //for (int i = 0; i < n; i++) cout << a[i] << ' ';
        
        ll sneakiness = 0;
        
        int ii = n;
        while (ii-- && a[ii] > 0)
            sneakiness += a[ii];
        
        int inverted = 0;
        for (int i = 0; i <= ii && a[i] < 0; i++)
        {
            inverted++;
            int inc = -a[i] - inverted * c;
            if (inc > 0)
                sneakiness += inc;
        }
        
        cout << sneakiness << '\n';
    }
    return 0;
}
#endif
