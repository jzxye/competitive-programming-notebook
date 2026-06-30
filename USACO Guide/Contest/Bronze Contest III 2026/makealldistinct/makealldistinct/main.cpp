#if 1

#include <iostream>
#include <set>
using namespace std;
using ll = long long;

const int NMAX = 200000;
int main()
{
    //O(TN^2logN)
    int T; cin >> T;
    while (T--)
    {
        int N, K; cin >> N >> K;
        int a[NMAX];
        for (int i = 0; i < N; i++) cin >> a[i];
        
        set<ll> distinct;
        int i = 0;
        int operations = 0;
        while (distinct.size() != N)
        {
            ll element = a[i];
            while(distinct.count(element))
            {
                operations++;
                element += K;
            }
            distinct.insert(element);
            ++i;
        }
        cout << operations << '\n';
    }
    return 0;
}

#endif
