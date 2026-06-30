#include <iostream>
#include <fstream>
using namespace std;

int getIndex(char f, char s, char t)
{
    int index = 0;
    switch(f)
    {
        case 'A':
            index += 0;
            break;
        case 'C':
            index += 16;
            break;
        case 'T':
            index += 32;
            break;
        case 'G':
            index += 48;
            break;
    }
    switch(s)
    {
        case 'A':
            index += 0;
            break;
        case 'C':
            index += 4;
            break;
        case 'T':
            index += 8;
            break;
        case 'G':
            index += 12;
            break;
    }
    switch(t)
    {
        case 'A':
            index += 0;
            break;
        case 'C':
            index += 1;
            break;
        case 'T':
            index += 2;
            break;
        case 'G':
            index += 3;
            break;
    }
    return index;
}

int main()
{
    ifstream fin ("cownomics.in");
    ofstream fout ("cownomics.out");
    
    int N, M; fin >> N >> M;
   // string genomes[200];
    string genomes[1000]; for (int i = 0; i < 2 * N; i++) fin >> genomes[i];
    //for silver N <= 500, M <= 50
    
    //bronze
   /* int count = 0;
    for (int i = 0; i < M; i++)
    {
        bool mutuallyExclusive = true;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (genomes[j][i] == genomes[N+k][i])
                {
                    mutuallyExclusive = false;
                    break;
                }
            }
        }
        if (mutuallyExclusive) count++;
    }*/
    
    //silver
    // brute force is too slow ( O(N^2 * M^3) )
    
    //observation: there are 64 possible sequences with A,C,T,G (4^3)
    // if one sequence is in spotted, it cannot be in plain (and vice versa)
    // a sequence cannot show up in both spotted and plain genomes
    
    // time complexity O(N * M^3)
    
    int count = 0;
    for (int mi = 0; mi < M-2; mi++)
    {
        for (int mj = mi+1; mj < M-1; mj++)
        {
            for (int mk = mj+1; mk < M; mk++)
            {
                bool mutuallyExclusive = true;
                
                bool inSpotted[64]{};
                for (int j = 0; j < N; j++)
                {
                    char f = genomes[j][mi], s = genomes[j][mj], t = genomes[j][mk];
                    inSpotted[getIndex(f, s, t)] = true;
                }
                
                bool inPlain[64]{};
                for (int k = 0; k < N; k++)
                {
                    char f = genomes[N+k][mi], s = genomes[N+k][mj], t = genomes[N+k][mk];
                    inPlain[getIndex(f, s, t)] = true;
                }
                
                for (int i = 0; i < 64; i++) if(inSpotted[i] && inPlain[i]) {mutuallyExclusive = false;}
                
                if (mutuallyExclusive) count++;
            }
        }
    }
    
    
    fout << count << '\n';
    return 0;
}
