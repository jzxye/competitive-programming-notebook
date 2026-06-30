#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n, f; cin >> n >> f;
    string contest; cin >> contest;
    
    map<string,int> moocounter;
    vector<string> moos(contest.size()-2);
    
    for (int i = 0; i <= contest.size()-3; i++) //identical moos cannot possibly overlap
    {
        string moo = contest.substr(i, 3);
        moos[i] = moo;

        if(moo[0] != moo[1] && moo[1] == moo[2])
        {
            moocounter[moo]++;
        }
    }
    
    map<string,bool> plusone;
    for (int i = 0; i <= contest.size()-3; i++)
    {
        string moo = contest.substr(i, 3);
        
        //case 1: change first character
        if (moo[1] == moo[2])
        {
            for (int a = 0; a < 26; a++)
            {
                if ('a'+a == moo[0] || 'a'+a == moo[1]) continue;

                string newmoo = moo;
                newmoo[0] = 'a' + a;
                if (i-2 >= 0 && moos[i-2] == newmoo) continue;
                if (i-1 >= 0 && moos[i-1] == newmoo) continue;
                
                plusone[newmoo] = true;
            }
        }
        else
        {
            //case 2: change second character
            if (moo[0] != moo[2])
            {
                string newmoo = moo;
                newmoo[1] = newmoo[2];
                if(!(i-1 >= 0 && moos[i-1] == newmoo) && !(i+1 <= contest.size()-3 && moos[i+1] == newmoo))
                    plusone[newmoo] = true;
            }
            //case 3: change third character
            if(moo[0] != moo[1])
            {
                string newmoo = moo;
                newmoo[2] = newmoo[1];
                if(!(i+2 <= contest.size()-3 && moos[i+2] == newmoo) && !(i+1 <= contest.size()-3 && moos[i+1] == newmoo))
                    plusone[newmoo] = true;
            }
        }
    }
    
    for (const auto &p : plusone)
        moocounter[p.first]++;
    
    vector<string> validMoos;
    for (const auto &p : moocounter)
    {
        if (p.second >= f) validMoos.push_back(p.first);
    }
    
    sort(validMoos.begin(), validMoos.end());
    
    cout << validMoos.size() << '\n';
    for (string s : validMoos)
        cout << s << '\n';
    
    
    //BEWARE F=1
    return 0;
}

