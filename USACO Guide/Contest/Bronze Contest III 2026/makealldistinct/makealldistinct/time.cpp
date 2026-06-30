#include <iostream>
#include <set>
using namespace std;
using ll = long long;

const int NMAX = 200000;
int main()
{
    int T; cin >> T;
    while (T--)
    {
        int N, K; cin >> N >> K;
       // int a[NMAX];
        int occurences[NMAX+1]{};
        for (int i = 0; i < N; i++)
        {
            int num; cin >> num;
          //  cin >> a[i];
            occurences[num]++;
        }
        
        ll operations = 0;

        // k > 0
        if (K > 0)
        {
            for (int i = 1; i <= N-K; i++)
            {
                if (occurences[i] > 1)
                {
                    int occ = occurences[i]-1;
                    occurences[i+K]+= occ;
                    occurences[i] -= occ;
                    operations += occ;
                }
            }
        }
        // k < 0
        else if (K < 0)
        {
            for (int i = N; i >= 1-K; i--)
            {
                if (occurences[i] > 1)
                {
                    int occ = occurences[i]-1;
                    occurences[i+K] += occ;
                    occurences[i] -= occ;
                    operations += occ;
                }
            }
        }

        for (int i = 1; i <= N; i++)
        {
            ll freq = occurences[i];
            if (freq > 1)
                operations += freq*(freq-1)/2;
        }

        cout << operations << '\n';
    }
    return 0;
}
