#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin ("outofplace.in");
    ofstream fout ("outofplace.out");
    
    int n; fin >> n;
    vector<int> order(n);
    for (int &m : order) fin >> m;
    
    vector<int> sorted(n);
    for (int i = 0; i < n; i++) sorted[i] = order[i];
    sort(sorted.begin(), sorted.end());
    
    int mismatch = 0;
    for (int i = 0; i < n; i++) if(sorted[i] != order[i]) mismatch++;
    
    fout << mismatch-1 << '\n';
    
    
    return 0;
}
