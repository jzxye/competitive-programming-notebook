#include <iostream>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    long long d[100000];
    long long moonies = k+1;
    
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        
        if (i == 0) continue;
        
        moonies += min(static_cast<long long>(k)+1, d[i] - d[i-1]);
    }
    
    cout << moonies << '\n';
    return 0;
}
