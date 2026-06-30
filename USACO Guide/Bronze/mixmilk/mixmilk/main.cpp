#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf ("mixmilk.in");
    ofstream outf ("mixmilk.out");
    
    
    int capacity[3];
    int milk[3];
    
    for (int i = 0; i < 3; i++)
        inf >> capacity[i] >> milk[i];
    
    for (int i = 0; i < 100; i++)
    {
        
        int amt = min(milk[i%3], capacity[(i+1)%3] - milk[(i+1)%3]);
        milk[i%3] -= amt;
        milk[(i+1)%3] += amt;
    }
    
    for (int i = 0; i < 3; i++)
        outf << milk[i] << '\n';
    
    return 0;
}
