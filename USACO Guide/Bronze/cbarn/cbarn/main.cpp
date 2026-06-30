#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
    ifstream fin ("cbarn.in");
    ofstream fout ("cbarn.out");
    
    int n; fin >> n;
    int r[1000]; for (int i = 0; i < n; i++) fin >> r[i];
    
    
    int minDist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int dist = 0;
        for (int j = i + 1; j < i + n; j++)
        {
            //dist += r[j] * min( n-abs(j-i), abs(j-i)); solved the wrong problem
            dist += r[j%n] * (j-i);
        }
        
        minDist = min(minDist, dist);
    }
    
    fout << minDist << '\n';
    
    return 0;
}
