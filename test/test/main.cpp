#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
using ll = long long;

const int NMAX = 100000;
const int QMAX = 10000;

int main()
{
    int N, Q; cin >> N >> Q;
    ll a[NMAX];
    for (int i = 0; i < N; i++) cin >> a[i];

    while (Q--)
    {
        int buckets; cin >> buckets;

        ll moonies = 0;
        int i = 0; //the current digit contributes 2^i buckets
        while (buckets > 0) //integer = 32 bits, loops max 32 times
        {
            int dig = buckets % 2;
            buckets /= 2;

            if (dig == 0)
            {
                i++;
                continue;
            }
            
            ll minMoonies = LLONG_MAX;
            for (int j = 0; j < N; j++)
            {
                minMoonies = min(minMoonies, a[j]* (1LL<<(max(0,i-j))));
            }
            moonies += minMoonies;

            i++;
        }
        cout << moonies << '\n';
    }
    return 0;
}
