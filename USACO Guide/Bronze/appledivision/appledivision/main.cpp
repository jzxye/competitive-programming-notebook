#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = long long;


void search(int k, int n, vector<ll> apples, vector<ll> subset, ll& leastDifference, ll totalWeight)
{
    if (k == n)
    {
        ll sum = 0;
        for (const ll &apple : subset) sum += apple;
        leastDifference = min(leastDifference, abs(totalWeight-2*sum));
    }
    else
    {
        search(k+1, n, apples, subset, leastDifference, totalWeight);
        subset.push_back(apples[k]);
        search(k+1, n, apples, subset, leastDifference, totalWeight);
        subset.pop_back();
    }
}

int main()
{
    int n; cin >> n;
    vector<ll> p(n);
    for (ll &pi : p) cin >> pi;
    
    ll weight = 0;
    for (ll &pi : p) weight += pi;

    vector<ll> subset;
    ll leastDifference = INT_MAX;
    search(0, n, p, subset, leastDifference, weight);
    
    cout << leastDifference << '\n';
    
    return 0;
}
