#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("pails.in");
    ofstream fout ("pails.out");
    
    int x, y, z; fin >> x >> y >> z;
    
    int most = 0;
    for (int i = 0; i <= z/y; i++)
    {
        
        most = max(most, i * y + (z - i * y)/x * x);
        
    }
    
    fout << most << '\n';

    return 0;
}
