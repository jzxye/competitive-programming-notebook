#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t; cin >> t;
    
    for (int ti = 0; ti < t; ti++)
    {
        int n; cin >> n;
        vector<int> a(n);
        
        int max = 0;
        int maxIndex = 0;
        for (int ni = 0; ni < n; ni++)
        {
            cin >> a[ni];
            if (a[ni] > max)
            {
                max = a[ni];
                maxIndex = ni;
            }
        }
        
        int target = 0;
        int i = 0;
        while (target < max)
        {
            target += a[i];
            i++;
        }
        
        int count = 0;
        int start = 0;
        for (;;)
        {
            int sum = 0;
            int end = start;
            do
            {
                sum += a[end];
                end++;
            }
            while(end < n && sum < target);
            
            if (sum == target)
            {
                count++;
                sum = 0;
                start = end;
                if (end == n) break;
            }
            else
            {
                target += a[i];
                i++;
                start = 0;
                count = 0;
            }

        }
        
        cout << n - count << '\n';
    }
    return 0;
}
