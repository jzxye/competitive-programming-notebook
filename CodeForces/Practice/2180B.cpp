#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    
    for (int i = 0; i < t; i++)
    {
        int n; cin >> n;
        
        vector<string> words(n);
        for (string &a : words) cin >> a;
        
        string answer;
        for (const string &word : words)
        {
            if (word + answer < answer + word)
                answer = word + answer;
            else
                answer += word;
        }
        cout << answer << '\n';
    }
}
