#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int main()
{
    //NOTE: this can be optimized to O(N)
    //HINT: maps are essentially "infinite" arrays. Does this problem require that?
    ifstream fin ("citystate.in");
    ofstream fout ("citystate.out");
    
    int n; fin >> n;
    
    map<string,map<string,int>> citystate;
    long long pairs = 0;
    for (int i = 0; i < n; i++)
    {
        string city, state;
        fin >> city >> state;
        city = city.substr(0, 2);
        
        if (citystate.count(state) && citystate[state].count(city) && city != state) // the final condition handles cities such as MI MI
            pairs+=citystate[state][city];
        citystate[city][state]++;
    }
    
    fout << pairs << '\n';
    return 0;

}
