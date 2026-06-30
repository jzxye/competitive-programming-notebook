#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin ("herding.in");
    ofstream fout ("herding.out");
    
    int pos[3]; for (int i = 0; i < 3; i++) fin >> pos[i];
    sort(pos, pos+3);
    
    int min;

    if (pos[1]-pos[0] == 1 && pos[2]-pos[1] == 1) min = 0;
    else if (pos[1] - pos[0] == 2 || pos[2] - pos[1] == 2) min = 1;
    else min = 2;
    
    int max = 0;
    
    max = std::max(pos[1]-pos[0]-1, pos[2]-pos[1]-1);
    
    fout << min << '\n';
    fout << max << '\n';
    
    return 0;
}
