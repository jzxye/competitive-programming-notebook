#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long;

const int NMAX = 100000;
const int QMAX = 10000;

int main()
{
    int N, Q; cin >> N >> Q;
    ll a[NMAX]; // a[i] is the price to buy 2^i(=1<<i) buckets
    for (int i = 0; i < N; i++) cin >> a[i];

    N = min(31, N);
    for (int i = 1; i < N; i++)
    {
        ll altPrice = 2*a[i-1];
        if (altPrice < a[i])
            a[i] = altPrice;
    }
    for (int i = N; i < 31; i++)
    {
        a[i] = 2*a[i-1];
    }

    while (Q--)
    {
        int x; cin >> x;
        //first: buy largest power of 2 available until x is less than the largest power of 2

        //second: do the cheaper of the two cases at each step
        //case 1: buy smallest power of 2 greater than x
        //case 2: buy the largest power of 2 less than x 

        //proof: because of our parsing of a[], a_i <= 2*a_{i-1} (i.e. buying a_{i-1} twice will never be better than buying a_i once)

        ll moonies = 0;
        ll minMoonies = LLONG_MAX;
        while (x > 0)
        {
            int digits = floor(log2(x)+1);
            int i = floor(log2(x));
            
            if (digits < N)
                minMoonies = min(minMoonies, moonies+a[digits]);
            
            moonies += a[i];
            x -= 1<<i;
        }
        minMoonies = min(minMoonies, moonies);
        
        cout << minMoonies << '\n';
    }
    return 0;
}


