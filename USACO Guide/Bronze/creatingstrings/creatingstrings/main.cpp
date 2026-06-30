#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
/*
int n;
string s;
vector<bool> chosen;
string permutation;
set<string> permutations;

int factorial(int num)
{
    if (num == 1 || num == 0) return 1;
    return num * factorial(num-1);
}

void search()
{
    if (permutation.size() == n)
    {
        permutations.insert(permutation);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(s[i]);
            search();
            permutation.pop_back();
            chosen[i] = false;
        }
    }
}

int main()
{
    cin >> s;
    n = static_cast<int>(s.size());
    chosen.resize(n);
    
//    int counter[26]{};
//    for (int i = 0; i < n; i++)
//        counter[s[i]-'a']++;
//
//    int numPermutations = factorial(n);
 //   for (int i = 0; i < 26; i++)
 //       numPermutations /= factorial(counter[i]);
    
    search();
    
    //cout << numPermutations << '\n';
    
    cout << permutations.size() << '\n';
    for (const string &p : permutations) cout << p << '\n';

    
    return 0;
}
*/
