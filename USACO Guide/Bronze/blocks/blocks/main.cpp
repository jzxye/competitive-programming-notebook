#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("blocks.in");
    ofstream fout ("blocks.out");
    
    int n; fin >> n;
    
    int letterCount[26]{};
    for (int i = 0; i < n; i++)
    {
        string word1, word2; fin >> word1 >> word2;
        int word1Letters[26]{};
        int word2Letters[26]{};
        for (char c : word1) word1Letters[c-'a']++;
        for (char c : word2) word2Letters[c-'a']++;
        for (int j = 0; j < 26; j++)
            letterCount[j] += max(word1Letters[j], word2Letters[j]);
    }
    
    for (int i = 0; i < 26; i++)
        fout << letterCount[i] << '\n';
    
    return 0;
}
