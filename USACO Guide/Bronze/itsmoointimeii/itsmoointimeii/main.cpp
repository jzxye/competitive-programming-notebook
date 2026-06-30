#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
    //NOTE: this is implementable in O(N) time
    int n; cin >> n;
    
    map<int,int> a; // {ai, # distinct numbers (that do not equal ai) showing up before last occurence of ai}
    map<int,int> occurences; // {number corresponding to 'o', # of moos}
    int distinct = 0;
    
    for (int i = 0; i < n; i++)
    {
        int ai; cin >> ai;
        if (a.count(ai))
        {
            occurences[ai] = a[ai];
            a[ai] = distinct-1;
        }
        else
        {
            a[ai] = distinct;
            distinct++;
        }
    }
    
    long long numMoos = 0; // max number of moos is of order N^2 ~ 10^12
    for (const auto &p : occurences)
        numMoos += p.second;
    
    cout << numMoos << '\n';
    
    return 0;
}
