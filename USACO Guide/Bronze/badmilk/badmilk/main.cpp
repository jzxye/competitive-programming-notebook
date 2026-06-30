#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAXN = 50;
const int MAXM = 50;
const int MAXT = 100;

int main()
{
    ifstream fin ("badmilk.in");
    ofstream fout ("badmilk.out");
    
    // n,m <= 50  t <= 100   d <= 1000
    int N, M, D, S; fin >> N >> M >> D >> S;

    //the milk drank at time t
    vector<int> timeline[/*N*/51][101];
    for (int i = 0; i < D; i++)
    {
        int p, m, t; fin >> p >> m >> t;
        timeline[p][t].push_back(m);
    }
    
    bool possiblePoison[51]; for (bool& b : possiblePoison) b = true;
    for (int i = 0; i < S; i++)
    {
        int p, t; fin >> p >> t;
        
        bool milkConsumed[51]{};
        for (int time = 1; time < t /*strictly earlie*/; time++)
            for (int milk : timeline[p][time])
                milkConsumed[milk] = true;

        for (int i = 1; i <= M; i++)
            possiblePoison[i] &= milkConsumed[i];
    }

    //how many times a milk was consumed by unique cows
    int milkCounter[51]{};
    for (int n = 1; n <= N; n++)
    {
        bool milkConsumed[51]{};

        for (int t = 1; t <= 100; t++)
        {
            for (int milk : timeline[n][t])
                milkConsumed[milk] = true;
        }
        
        for (int m = 1; m <= M; m++)
            if (milkConsumed[m]) milkCounter[m]++;
    }
    
    int doses = 0;
    for (int i = 1; i <= M; i++)
    {
        if (possiblePoison[i])
            doses = max(doses, milkCounter[i]);
    }
    
    fout << doses << '\n';
    
    return 0;
}
