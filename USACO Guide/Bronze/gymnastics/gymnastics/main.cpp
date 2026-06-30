#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("gymnastics.in");
    ofstream fout ("gymnastics.out");
    
    int k, n; fin >> k >> n;
    
    bool consistent[20][20];
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            consistent[i][j] = true;
    
    for (int i = 0; i < k; i++)
    {
        int ranking[20];
        for (int j = 0; j < n; j++)
        {
            fin >> ranking[j];
        }
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < n; l++)
            {
                if (l <= j) consistent[ranking[j]-1][ranking[l]-1] = false;
                else consistent[ranking[j]-1][ranking[l]-1] = consistent[ranking[j]-1][ranking[l]-1] && true;
            }
        }
    }
    
    int pairs = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(consistent[i][j] || consistent[j][i]) pairs++;
        }
    }
    fout << pairs << '\n';
    
    return 0;
}
