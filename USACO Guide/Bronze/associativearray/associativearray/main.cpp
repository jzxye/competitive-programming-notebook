#include <iostream>
#include <map>
using namespace std;

int main()
{
    int q; cin >> q;
    
    map<long long,long long> a;
    
    for (int i = 0; i < q; i++)
    {
        int query; cin >> query;
        
        if (query == 0)
        {
            long long k, v; cin >> k >> v;
            a[k] = v;
        }
        else if (query == 1)
        {
            long long k; cin >> k;
            cout << a[k] << '\n';
        }
    }
    return 0;
}
