#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //overflow analysis: maximum sum ~ n^3 * a_max * b_max ~ 10^19
    int n; cin >> n;
    vector<long long> a(n); for (long long &ai : a) cin >> ai;
    vector<int> b(n); for (int &bi : b) cin >> bi;
    
    for (long long i = 0; i < n; i++) a[i] *= (i+1) * (n-i); //multiply by number of subarrays containing a[i]
    
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += a[i] * b[i];
    
    cout << sum << '\n';
    
    return 0;
}
