#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf ("shuffle.in");
    ofstream outf ("shuffle.out");
    
    int n; inf >> n;
    int shuffle[100]; for (int i = 0; i < n; i++) inf >> shuffle[i];
    int order[100]; for (int i = 0; i < n; i++) inf >> order[i];
    
    for (int swap = 0; swap < 3; swap++)
    {
        int oldOrder[100];
        for (int i = 0; i < n; i++)
            oldOrder[i] = order[shuffle[i]-1];
        //subtract 1 to convert to indexe
        
        for (int i = 0; i < n; i++)
            order[i] = oldOrder[i];
    }
    
    for (int i = 0; i < n; i++)
        outf << order[i] << '\n';
    
    return 0;
}
