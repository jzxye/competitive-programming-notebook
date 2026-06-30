#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    
    //even + even = even
    //odd + odd = even
    //even + odd = odd
    
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        if (num % 2 == 0) even++;
        else odd++;
    }
    
    while (even < odd)
    {
        odd-=2;
        even++;
    }
    if (even > odd)
        cout << odd * 2 + 1 << '\n';
    else if (even == odd)
        cout << odd * 2 << '\n';
    
        
    return 0;
}
