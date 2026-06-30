#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> b(n+1); for (int i = 1; i <= n; i++) cin >> b[i];
    vector<int> c(n+1); for (int i = 1; i <= n; i++) cin >> c[i];
    
    //how many values of j given a value of b;
    vector<int> j(n+1);
    for (int i = 1; i <= n; i++) j[b[c[i]]]++;
    
    //max value N^2 ~ 10^10
    long long count = 0;
    for (int i = 1; i <= n; i++) count += j[a[i]];
    
    cout << count << '\n';
    
   /* map<int,int> i_a;
    map<int,vector<int>> b_i;
    map<int,vector<int>> c_i;
    
    for (int i = 1; i <= n; i++) cin >> i_a[i];
    for (int i = 1; i <= n; i++)
    {
        int b; cin >> b;
        b_i[b].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        int c; cin >> c;
        c_i[c].push_back(i);
    }
    
    //a_i = b_(c_j)
    //Time Complexity: O(N^2logN)
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        int a = i_a[i];
        if (b_i.count(a))
        {
            for (const int &c : b_i[a])
            {
                if (c_i.count(c))
                    count += c_i[c].size();
            }
        }
    }*/
    

    
    
    return 0;
}
