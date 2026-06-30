//
//  longerultrahand.cpp
//  CodeSprint2026
//
//  Created by Joshua Ye on 5/9/26.
//

#include <iostream>
using namespace std;
using ll = long long;

int NMAX = 200000;

int main()
{
    int N, x, y; cin >> N >> x >> y;
    int totalLength = 0;
    
    int L[NMAX]; for (int i = 0; i < N; i++) cin >> L[i];
    
    if (N==1)
    {
        int totalL = 0;
        for (int i = 0; i < N; i++) totalL += L[i];
        
        if(totalLength*totalLength != x*x + y*y)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    else
    {
        if(totalLength*totalLength >= x*x + y*y)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    
    return 0;
}
