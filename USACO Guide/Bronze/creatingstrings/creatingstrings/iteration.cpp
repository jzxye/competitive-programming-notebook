#include <set>
#include <iostream>
#include <string>
using namespace std;

bool included[8]{};
void permute(set<string> &permutations, const string &s, string p, const int &n)
{
    if(p.size() == n)
    {
        permutations.insert(p);
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(!included[i])
        {
            included[i] = true;
            p += s[i];
            permute(permutations, s, p, n);
            included[i] = false;
            p.pop_back();
        }
    }
}


int main()
{
    string s; cin >> s;
    int n = static_cast<int>(s.size());
    
    set<string> permutations;
    
    permute(permutations, s, "", n);
    
    cout << permutations.size() << '\n';
    for (string s : permutations)
        cout << s << '\n';

    return 0;
}
