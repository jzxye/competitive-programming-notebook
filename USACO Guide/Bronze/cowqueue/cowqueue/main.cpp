#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream fin ("cowqueue.in");
    ofstream fout ("cowqueue.out");
    
    int n; fin >> n;
    vector<pair<int,int>> queue(n);
    for (pair <int,int> &p : queue) fin >> p.first >> p.second;
    
    sort(queue.begin(), queue.end());
    
    int time = 0;
    for (pair p : queue)
    {
        time = max(time, p.first);
        time += p.second;
    }
    
    fout << time << '\n';

    
    return 0;
}
