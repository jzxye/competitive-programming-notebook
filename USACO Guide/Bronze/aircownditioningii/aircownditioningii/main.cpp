#include <iostream>
#include <utility>
#include <climits>
using namespace std;

const int NMAX = 20;
const int MMAX = 10;
const int BARN_LENGTH = 100;

int main()
{
    int N, M; cin >> N >> M;
    int s[NMAX], t[NMAX], c[NMAX];
    for (int i = 0; i < N; i++)
        cin >> s[i] >> t[i] >> c[i];
    
    int a[MMAX], b[MMAX], p[MMAX], m[MMAX];
    for (int i = 0; i < M; i++)
        cin >> a[i] >> b[i] >> p[i] >> m[i];
    
    int minCost = INT_MAX;

    for (int mask = 0; mask < (1<<M); mask++)
    {
        int cooled[BARN_LENGTH]{};
        int cost = 0;
        for (int i = 0; i < M; i++)
        {
            if (mask & 1<<i)
            {
                for (int ii = a[i]; ii <= b[i]; ii++)
                    cooled[ii] += p[i];
                
                cost += m[i];
            }
        }
        
        bool valid = true;
        for (int i = 0; i < N; i++)
            for (int ii = s[i]; ii <= t[i]; ii++)
                valid &= cooled[ii] >= c[i];
        
        if(valid)
            minCost = min(minCost, cost);
    }
    
    cout << minCost << '\n';
    return 0;
}
