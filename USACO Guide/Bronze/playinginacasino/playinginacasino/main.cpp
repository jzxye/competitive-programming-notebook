#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    //observation: there is a closed expression for the sum if we know the order from least to greatest
    //time complexity O(tmnlogn)
    int t; cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        int n, m; cin >> n >> m;
        vector<vector<int>> cards(m);
        for (int ni = 0; ni < n; ni++)
        {
            for (int mi = 0; mi < m; mi++)
            {
                int c; cin >> c;
                cards[mi].push_back(c);
            }
        }
        
        for (int mi = 0; mi < m; mi++)
        {
            sort(cards[mi].begin(), cards[mi].end());
        }
        
        //max sum occurs for nm = 3e5, c = {1e6, 1e6, ..., 1, 1, ...}
        //on order 3e5 * 1e6
        long long sum = 0;
        for(int ni = 0; ni < n; ni++)
        {
            for (int mi = 0; mi < m; mi++)
            {
                sum += ni * static_cast<long long>(cards[mi][ni]);
                sum -= (n-ni-1) * static_cast<long long>(cards[mi][ni]);
            }
        }
        cout << sum << '\n';
        
        
    }
    return 0;
}
