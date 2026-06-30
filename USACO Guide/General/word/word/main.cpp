#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf ("word.in");
    ofstream outf ("word.out");
    
    int n, k; inf >> n >> k;
    
    int charsOnLine {0};
    for (int i = 0; i < n; i++)
    {
        string word;
        inf >> word;
        if (word.size() + charsOnLine > k)
        {
            outf << '\n';
            charsOnLine = 0;
        }
        if (charsOnLine != 0)
            outf << ' ';
        outf << word;
        charsOnLine += word.size();
    }
    
    return 0;
}
