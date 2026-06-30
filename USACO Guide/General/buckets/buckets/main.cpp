#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream inf ("buckets.in");
    ofstream outf ("buckets.out");
    
    int barnR, barnC, lakeR, lakeC, rockR, rockC;
    for (int row = 0; row < 10; row++)
    {
        for (int col = 0; col < 10; col++)
        {
            char c;
            inf >> c;
            if (c == 'B')
            {
                barnR = row;
                barnC = col;
            }
            else if (c == 'L')
            {
                lakeR = row;
                lakeC = col;
            }
            else if (c == 'R')
            {
                rockR = row;
                rockC = col;
            }
        }
    }
    
    
    if ((barnR == lakeR && lakeR == rockR && (min(barnC, lakeC) < rockC && rockC < max(barnC, lakeC))) ||
        (barnC == lakeC && lakeC == rockC && (min(barnR, lakeR) < rockR && rockR < max(barnR, lakeR))))
        outf << abs(barnR - lakeR) + abs(barnC - lakeC) + 1 << '\n';
    else
        outf << abs(barnR - lakeR) + abs(barnC - lakeC) - 1 << '\n';

    return 0;
}
