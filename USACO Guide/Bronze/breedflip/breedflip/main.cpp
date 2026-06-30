#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin ("breedflip.in");
    ofstream fout ("breedflip.out");
    
    int n; fin >> n;
    string a, b; fin >> a >> b;
    
    bool correct[1000]; for (int i = 0; i < n; i++) correct[i] = a[i] == b[i];
    
    bool last = true;
    int incorrect = 0;
    for (int i = 0; i < n; i++)
    {
        if (!last && correct[i]) incorrect++;
        last = correct[i];
    }
    if (!last) incorrect++;
    
    fout << incorrect << '\n';
    
    return 0;
}
