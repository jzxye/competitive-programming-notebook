
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
   //     vector<int> a(n);

        cout << n;
        for(int i = n-1; i > 0; i--)
            cout << ' ' << i;
        cout << '\n';
    }
    return 0;
}

