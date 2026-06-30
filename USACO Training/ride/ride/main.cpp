/*
ID: joshua.41
LANG: C++
TASK: ride
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    
    string comet, group;
    
    int cprod = 1;
    int gprod = 1;
    
    fin >> comet >> group;
    
    for (int i = 0; i < comet.size(); i++)
        cprod *= (comet[i] - 'A' + 1);
    for (int i = 0; i < group.size(); i++)
        gprod *= (group[i] - 'A' + 1);
    
    if (cprod % 47 == gprod % 47)
        fout << "GO" << '\n';
    else
        fout << "STAY" << '\n';
    
    
    return 0;
}
