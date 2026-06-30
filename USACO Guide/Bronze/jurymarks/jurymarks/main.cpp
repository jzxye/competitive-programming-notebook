#include <iostream>
#include <vector>
#include <set>
using namespace std;


int main()
{
    //Time Complexity O(NKlogK)
    //observation: different starting scores cannot result in the same ending scores
    // n <= k <= 2000
    int k, n; cin >> k >> n;
    vector<int> a(k); for (int &ai : a) cin >> ai;
    vector<int> b(n); for (int &bi : b) cin >> bi;
    
    vector<int> change(k);
    change[0] = a[0];
    for (int i = 1; i < k; i++) change[i] = change[i-1] + a[i];
    
    set<int> starting;
    for (int i = 0; i < k; i++)
    {
        int initial = b[0] - change[i];
        set<int> scores; for (int j = 0; j < k; j++) scores.insert(initial + change[j]);
        
        bool valid = true;
        for (int j = 0; j < n; j++) valid = valid && scores.count(b[j]); // can also use operator &=
        if (valid) starting.insert(initial);
        
    }
    cout << starting.size() << '\n';
    
    return 0;
}
