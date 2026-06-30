#if 0

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t; cin >> t;
    
    while (t--)
    {
        int n; cin >> n;
        vector<int> p(n); for (int &pi : p) cin >> pi;
        vector<bool> marked(n);
        int count = 0;
        
        for (int i = 1; i <= n; i++)
        {
            if (marked[i-1]) continue;
            
            if(p[i-1] <= i)
            {
                count++;
                marked[p[i-1]-1] = true; //this is not necessary because it doesn't affect future sits
            }
        }
        
        cout << count << '\n';
    }
    return 0;
}

#endif
