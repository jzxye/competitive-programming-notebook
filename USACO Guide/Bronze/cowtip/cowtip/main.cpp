#include <iostream>
#include <fstream>
using namespace std;

int flip (bool tipped[][10], int r, int c)
{

    if (tipped[r][c])
    {
        for (int i = 0; i <= r; i++)
            for (int j = 0; j <= c; j++)
                tipped[i][j] = !tipped[i][j];
        return 1;
    }
    
    return 0;
}

int main()
{
    ifstream fin ("cowtip.in");
    ofstream fout ("cowtip.out");
    
    int n; fin >> n;
    bool tipped[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            fin >> c;
            tipped[i][j] = c - '0';
        }
    }
    
    int flips = 0;
    for (int i = n-1; i >= 0; i--)
    {
        flips += flip(tipped, i, i);
        for (int j = 1; j <= i; j++)
            flips += flip(tipped, i-j, i) + flip(tipped, i, i-j);
    }
    
    fout << flips << '\n';
    
    return 0;
}
