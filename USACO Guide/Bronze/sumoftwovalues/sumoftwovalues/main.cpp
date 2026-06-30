#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    
    //M1: Hashmap
    map<int,int> a;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        if(a.count(x-ai))
        {
            cout << i << ' ' << a[x-ai] << '\n';
            return 0;
        }
        a[ai] = i;
    }
    cout << "IMPOSSIBLE" << '\n';
    
    //M2: Two Pointers
    /*vector<pair<int,int>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    
    sort(a.begin(), a.end());
    
    int l = 0;
    int r = n-1;
    
    for (;;)
    {
        while(r > 0 && a[l].first + a[r].first > x) r--;
        
        if (!(l < r)) break;
        
        if (a[l].first + a[r].first == x)
        {
            cout << a[l].second << ' ' << a[r].second << '\n';
            return 0;
        }
        
        l++;
    }

    cout << "IMPOSSIBLE" << '\n';*/
    
    return 0;
    
}
