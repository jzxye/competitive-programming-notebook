#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin ("notlast.in");
    ofstream fout ("notlast.out");
    
    int n; fin >> n;
    string cows[7]{"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string,int> log; for (int i = 0; i < 7; i++) log[cows[i]] = 0;
    
    for (int i = 0; i < n; i++)
    {
        string name; int milk;
        fin >> name >> milk;
        log[name] += milk;
    }
    
    vector<pair<int,string>> ranking;
    for (const auto &l : log) ranking.push_back({l.second, l.first});
    sort(ranking.begin(), ranking.end());
    
    int m = ranking[0].first;
    
    int l = 0, r = 6;
    while (l < 6 && ranking[l].first <= m) l++;
    while (r > 0 && ranking[r].first > ranking[l].first) r--;
    
    if (ranking[l].first == m || r != l) fout << "Tie" << '\n';
    else fout << ranking[r].second << '\n';
    
    
    return 0;
}
