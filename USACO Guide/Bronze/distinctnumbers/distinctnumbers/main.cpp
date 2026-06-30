#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    int n; cin >> n;
    
    //M1
    /*vector<int> x(n);
    for (int &i : x) cin >> i;
    
    sort(x.begin(), x.end());
    
    int distinct = 1;
    for (int i = 1; i < n; i++)
    {
        if (x[i] == x[i-1]) continue;
        distinct++;
    }
    
    cout << distinct << '\n';*/
    
    //M2
    set<int> x;
    for (int i = 0; i < n; i++)
    {
        int xi; cin >> xi;
        x.insert(xi);

    }
    
    cout << x.size() << '\n';
    
    return 0;
}
