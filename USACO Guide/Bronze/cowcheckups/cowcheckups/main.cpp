#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vector <int> b(n); for (int i = 0; i < n; i++) cin >> b[i];
    
    
    vector <int> c(n+1);
    
    //TIME LIMIT O(N^3)
    /*
    for (int l = 0; l < n; l++)
    {
        for (int r = l; r < n; r++)
        {
            int checked = 0;
            for (int i = 0; i < n; i++)
            {
                if (l <= i && i <= r)
                {
                    if (a[r-(i-l)] == b[i]) checked++;
                }
                else if (a[i] == b[i]) checked++;
            }
            c[checked]++;
        }
    }*/
    
    //O(N^2)
    int checked_i = 0;
    for (int i = 0; i < n; i++) if (a[i] == b[i]) checked_i++;
    
    for (int middle = 0; middle < 2 * n; middle++)
    {
        int l, r;

        if (middle % 2 == 0) {l = r = middle/2;}
        else { l = middle/2; r = middle/2 + 1;}

        int checked_f = checked_i;
        for (; l >= 0 && r < n; l--, r++)
        {
            int before = (a[l] == b[l]) + (a[r] == b[r]);
            int after = (a[l] == b[r]) + (a[r] == b[l]);
            
            checked_f += after-before;
            c[checked_f]++;
        }
    }
    
    for (int i = 0; i < n+1; i++)
        cout << c[i] << '\n';
    
    return 0;
}
