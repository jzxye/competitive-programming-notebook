#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin ("angry.in");
    ofstream fout ("angry.out");
    
    int n; fin >> n;
    vector<int> x(n); for (int &xi : x) fin >> xi;
    
    sort(x.begin(), x.end());

    
    int maxBales = 0;
    for (int i = 0; i < n; i++)
    {
        int radius = 1;
        int l; l = i;
        int lower;
        for(;;)
        {
            lower = x[l] - radius;
            
            bool done = true;
            while (l > 0 && x[l-1] >= lower)
            {
                l--;
                done = false;
            }
            
            if (done) break;
            
            radius++;
        }
        
        radius = 1;
        int r; r = i;
        int upper;
        for(;;)
        {
            upper = x[r] + radius;
        
            bool done = true;
            while (r < n-1 && x[r+1] <= upper)
            {
                r++;
                done = false;
            }
            
            if (done) break;
            
            radius++;
        }
        maxBales = max(maxBales, r-l+1);
    }
    
    fout << maxBales << '\n';
    return 0;
}
