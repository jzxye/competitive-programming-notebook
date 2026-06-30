#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> c(n); for (int &ci : c) cin >> ci;
    sort(c.rbegin(), c.rend());
    
    long long maxProfit = 0;
    int tuition = 0;
    for (int i = 0; i < n; i++)
    {
        long long profit = static_cast<long long>(c[i]) * (i+1);
        if (profit >= maxProfit)
        {
            maxProfit = profit;
            tuition = c[i];
        }
    }
    
    cout << maxProfit << ' ' << tuition << '\n';
    
    return 0;
}
