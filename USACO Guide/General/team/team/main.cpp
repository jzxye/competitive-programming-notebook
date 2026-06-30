//
//  main.cpp
//  team
//
//  Created by Joshua Ye on 12/16/25.
//

#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    
    int implemented {0};
    for (int i = 0; i < n; i++)
    {
        int p, v, t;
        cin >> p >> v >> t;
        if (p + v + t >= 2)
            implemented++;
    }
    cout << implemented << '\n';
    return 0;
}
