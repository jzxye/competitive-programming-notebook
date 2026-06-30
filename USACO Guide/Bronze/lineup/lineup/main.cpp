#if 0


#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_COWS = 8;
const int NMAX = 7;

struct cowPair
{
    string c1;
    string c2;
};

int main()
{
    ifstream fin ("lineup.in");
    ofstream fout ("lineup.out");
    string lineup[NUM_COWS] = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    
    int N; fin >> N;
    cowPair constraints[NMAX];
    
    for (int i = 0; i < N; i++)
    {
        string c1, c2;
        string garbage;
        fin >> c1 >> garbage >> garbage >> garbage >> garbage >> c2;
        
        constraints[i].c1 = c1;
        constraints[i].c2 = c2;
    }
    
    do
    {
        bool satisfied[NMAX]{};

        int i = NUM_COWS-1;
        for(;;)
        {
            int ii = i--;
            
            for (int c = 0; c < N; c++)
            {
                if ((lineup[i] == constraints[c].c1 && lineup[ii] == constraints[c].c2)
                    || (lineup[i] == constraints[c].c2 && lineup[ii] == constraints[c].c1))
                    satisfied[c] = true;
            }
            
            if(i == 0) break;
        }
        
        bool valid = true;
        for (int i = 0; i < N; i++)
            valid &= satisfied[i];
        
        if (valid)
        {
            for (int i = 0; i < NUM_COWS; i++)
                fout << lineup[i] << '\n';
            return 0;
        }
    }
    while (next_permutation(lineup, lineup + NUM_COWS));
    
    return 0;
}

#endif
