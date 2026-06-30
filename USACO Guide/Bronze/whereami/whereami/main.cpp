#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    ifstream fin ("whereami.in");
    ofstream fout ("whereami.out");
    
    int n; fin >> n;
    string mailbox; fin >> mailbox;
    
    for (int k = 1; k <= n; k++)
    {
        set<string> colors;
        for (int i = 0; i <= n-k; i++)
        {
            colors.insert(mailbox.substr(i, k));
        }
            
        if(colors.size() == n-k+1)
        {
            fout << k << '\n';
            break;
        }
    }
    return 0;
}
