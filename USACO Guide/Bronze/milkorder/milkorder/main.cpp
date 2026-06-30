#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin ("milkorder.in");
    ofstream fout ("milkorder.out");
    
    int n, m, k; fin >> n >> m >> k;
    
    bool oneInHierarchy = false;
    
    vector<int> order(n);
    vector<int> hierarchy(m);
    for (int &cow : hierarchy)
    {
        fin >> cow;
        if (cow == 1) oneInHierarchy = true;
    }
    
    //place fixed cows
    for (int i = 0; i < k; i++)
    {
        int c, p; fin >> c >> p;
        p--;
        // if (c == 1) {fout << p << '\n'; return 0;}
        order[p] = c;
    }
    
    if (!oneInHierarchy)
    {
        //place cows in hierarchy last to first
        for (int i = m-1; i >= 0; i--)
        {
            bool fixed = false;
            for (int p = 0; p < n; p++) fixed |= (order[p] == hierarchy[i]);
            if (fixed) continue;
            
            int pos = -1;
            for (int p = 0; p < n; p++)
            {
                if (order[p] == 0) pos = p;
                else if (i < m-1 && order[p] == hierarchy[i+1]) break;
            }
            
            order[pos] = hierarchy[i];
        }
    }
    else
    {
        //place cows in hierarchy first to last
        for (int i = 0; i < m; i++)
        {
            bool fixed = false;
            for (int p = 0; p < n; p++) fixed |= (order[p] == hierarchy[i]);
            if (fixed) continue;
            
            int pos = -1;
            for (int p = n-1; p >= 0; p--)
            {
                if (order[p] == 0) pos = p;
                else if (i > 0 && order[p] == hierarchy[i-1]) break;
            }
            
            order[pos] = hierarchy[i];
        }
    }
    
    
    
    //print position of cow 1, or first empty position
    int first = -1;
    for (int i = 0; i < n; i++)
    {
        if (first == -1 && order[i] == 0) first = i+1;
        if (order[i] == 1)
        {
            fout << i+1 << '\n';
            return 0;
        }
    }
    fout << first << '\n';
    return 0;
}
