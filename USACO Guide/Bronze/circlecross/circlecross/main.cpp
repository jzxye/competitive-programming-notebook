#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("circlecross.in");
    ofstream fout ("circlecross.out");
    
    int pos[2][26];
    int occurence[26]{};
    for (int i = 0; i < 52; i++)
    {
        char c; fin >> c;
        pos[occurence[c-'A']][c-'A'] = i;
        occurence[c-'A']++;
    }
    
    int pairs = 0;
    for (int c1 = 0; c1 < 25; c1++)
    {
        for (int c2 = c1+1; c2 < 26; c2++)
        {
            if ((pos[0][c2] < pos[0][c1] && pos[0][c1] < pos[1][c2] && pos[1][c2] < pos[1][c1] )
                || (pos[0][c1] < pos[0][c2] && pos[0][c2] < pos[1][c1] && pos[1][c1] < pos[1][c2]))
                pairs++;
        }
    }
    fout << pairs << '\n';
    
    return 0;
}
