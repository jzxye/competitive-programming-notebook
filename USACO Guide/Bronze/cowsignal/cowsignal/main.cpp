#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf ("cowsignal.in");
    ofstream outf ("cowsignal.out");
    int m, n, k; inf >> m >> n >> k;
    
    for (int i = 0; i < m; i++)
    {
        string line {""};
        for (int j = 0; j < n; j++)
        {
            char c; inf >> c;
            for (int l = 0; l < k; l++)
                line += c;
        }
        
        for (int l = 0; l < k; l++)
        {
            outf << line << '\n';
        }
    }
    
    return 0;
}
