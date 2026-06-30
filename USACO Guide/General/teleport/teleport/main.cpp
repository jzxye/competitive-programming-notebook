#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    ifstream inf ("teleport.in");
    ofstream outf ("teleport.out");
    
    int a, b, x, y; inf >> a >> b >> x >> y;
    
    outf << min(abs(a-b), min(abs(a-x) + abs(y-b), abs(a-y) + abs(x-b))) << '\n';

    return 0;
}
