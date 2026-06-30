#include <iostream>
using namespace std;

int main()
{
    int n; cin >> n;
    int x[5000], y[5000];
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    
    int square = 0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            square = max((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]), square);
        }
    }
    
    cout << square << '\n';
    return 0;
}
