#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

const int NUM_COWS = 8;
const int NMAX = 7;

int main()
{
    ifstream fin ("lineup.in");
    ofstream fout ("lineup.out");
    
    string names[NUM_COWS] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    map<string, int> nameToInd;
    for (int i = 0; i < NUM_COWS; i++)
        nameToInd.insert({names[i], i});
    
    
    vector<int> adj[NUM_COWS];

    int N; fin >> N;
    for (int i = 0; i < N; i++)
    {
        string c1, c2;
        string garbage;
        fin >> c1 >> garbage >> garbage >> garbage >> garbage >> c2;
        
        adj[nameToInd[c1]].push_back(nameToInd[c2]);
        adj[nameToInd[c2]].push_back(nameToInd[c1]);
    }
    
    bool printed[NUM_COWS]{};
    for (int i = 0; i < NUM_COWS; i++)
    {
        if(printed[i] || adj[i].size() == 2) continue;
        
        fout << names[i] << '\n';
        printed[i] = true;
        
        if(!adj[i].empty())
        {
            int curr = i;
            int next = adj[i][0];

            
            while (adj[next].size() == 2)
            {
                fout << names[next] << '\n';
                printed[next] = true;
                
                int ii = adj[next][0] == curr ? 1 : 0;
                curr = next;
                next = adj[next][ii];
                
//                fout << names[adj[next][ii]] << '\n';
//                printed[adj[next][ii]] = true;
//                curr = next;
//                next = adj[next][ii];
            }
            fout << names[next] << '\n';
            printed[next] = true;
            
//            fout << names[adj[next][0]] << '\n';
//            printed[adj[next][0]] = true;
        }
    }
    
    return 0;
}
