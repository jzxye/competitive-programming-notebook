#include <iostream>
using namespace std;

int main()
{
    int k, n, w; cin >> k >> n >> w;
    int cost = w * (w+1) / 2 * k;
    
    if (n < cost) cout << cost - n << '\n';
    else cout << 0 << '\n';
    
    return 0;
}
