#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream inf ("lostcow.in");
    ofstream outf("lostcow.out");
    
    int x, y; inf >> x >> y;
    
    y -= x;
    x = 0;
    
    int target = 1;
    int distance = 0;
    
    for (;;)
    {
        distance += abs(target);
        
        if (abs(target) >= abs(y) && target/abs(target) == y/abs(y))
        {
            distance -= abs(y - target);
            break;
        }
        
        distance += abs(target);
        target *= -2;
    }
    
    outf << distance << '\n';
    
    return 0;
}
