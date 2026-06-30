#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> w(2 * n); for (int i = 0; i < 2 * n; i++) cin >> w[i];
    
    sort(w.begin(), w.end());
    
    int minInstability = INT_MAX;
    
    for (int p1 = 0; p1 < 2*n-1; p1++)
    {
        for (int p2 = p1+1; p2 < 2*n; p2++)
        {
            int instability = 0;
            bool small = true;
            for (int i = 0; i < 2 * n; i++)
            {
                if (i == p1 || i == p2) continue;
                
                instability += small ? -w[i] : w[i];
                small = !small;
            }
            minInstability = min(minInstability, instability);
        }
    }
    
    cout << minInstability << '\n';
    return 0;
}

