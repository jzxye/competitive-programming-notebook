#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    
    ifstream inf ("blist.in");
    ofstream outf("blist.out");
    
    int n; inf >> n;
    int buckets[1000]{};
    for (int i = 0; i < n; i++)
    {
        int s, t, b; inf >> s >> t >> b;
        
        for (int i = s; i < t; i++)
        {
            buckets[i] += b;
        }
    }
    
    int maxBuckets = 0;
    for (int i = 0; i < 1000; i++)
        maxBuckets = max(maxBuckets, buckets[i]);
    
    outf << maxBuckets << '\n';

    return 0;
}
