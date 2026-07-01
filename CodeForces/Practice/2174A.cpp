#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
     Needle in a haystack
     
     */
    int T; cin >> T;
    for (int word = 0; word < T; word++)
    {
        string s, t; cin >> s >> t;
        int letters[26]{};
        
        bool impossible = false;
        for (char c : t) letters[c-'a']++;
        for (char c : s)
        {
            if(letters[c-'a'] == 0)
            {
                impossible = true;
                break;
            }
            else letters[c-'a']--;
        }
        
        if(impossible)
        {
            cout << "Impossible" << '\n';
            continue;
        }
        
        int i, j; i = j = 0;

        while(i < 26 && j < s.size())
        {
            if (letters[i] == 0)
            {
                i++;
            }
            else if('a'+i < s[j])
            {
                cout << static_cast<char>('a'+i);
                letters[i]--;
            }
            else
            {
                cout << s[j];
                j++;
            }
           /* if (i == 26)
            {
                while (j < s.size())
                {
                    cout << s[j];
                    j++;
                }
            }
            else if (j == s.size())
            {
                while (i < 26)
                {
                    while (letters[i] != 0)
                    {
                        cout << static_cast<char>('a'+i);
                        letters[i]--;
                    }
                    
                    while (i < 26 && letters[i] == 0) i++;
                }
            }*/
        }
        
        while (j < s.size())
        {
            cout << s[j];
            j++;
        }
        
        for (int i = 0; i < 26;i++)
            while (letters[i]--)
                cout << static_cast<char>('a'+i);
                    
        
        cout << '\n';
    }
    
    return 0;
}