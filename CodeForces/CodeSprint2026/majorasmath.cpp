//
//  main.cpp
//  Majora's Math
//
//  Created by Joshua Ye on 5/9/26.
//

#include <iostream>
using namespace std;

int main()
{
    int h; int n; cin >> h >> n;
    int a,b,c,d; cin >> a >> b >> c >> d;
    
    while (n--)
    {
        string arrow; cin >> arrow;
        
        if (arrow == "standard")
            h-=a;
        else if (arrow == "fire")
            h-=b;
        else if (arrow == "ice")
            h-=c;
        else //light
            h-=d;
        
        if (h<=0)
        {
            cout << "dead" << '\n';
            return 0;
        }
    
    }
    cout << h << '\n';
}


