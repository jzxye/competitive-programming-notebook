#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("censor.in");
    ofstream fout ("censor.out");
    
    string s, t; fin >> s >> t;
    
    string censored = "";
    
    for (int i = 0; i < s.size(); i++)
    {
        censored += s[i];

        if (censored.size() >= t.size() && censored.substr(censored.size()-t.size(), t.size()) == t)
            for (int j = 0; j < t.size(); j++) //this is equivalent to censored.resize(censored.size() - t.size());
                censored.pop_back();
    }
    
   // TOO SLOW
 /*
    
    for (int i = 0; i < s.size()-t.size()+1; i++)
    {
        if(s[i] == t[0])
        if (s.substr(i, t.size()) == t)
        {
            s = s.substr(0, i) + s.substr(i+t.size(), s.size()-i-t.size());
            i = max(0, static_cast<int>(i - t.size())); //note that i++ is called right after this
        }
    }
    fout << s << '\n';
  
  */
    
    
    fout << censored << '\n';
    
    return 0;
}
