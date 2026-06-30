#include <iostream>
#include <fstream>
using namespace std;

int getIndex(string arr[], string s, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == s) return i;
    return -1;
}
int main()
{
    ifstream fin ("guess.in");
    ofstream fout ("guess.out");
    
    //to maximize "yes" answers, there must be zero "no" answers
    //questions must only be about the target animal -> we can loop over the animals
    
    
    int n; fin >> n;
    string characteristics[10000]; int nc = 0;
    bool is[100][10000]{};
    int k[100];
    for (int i = 0; i < n; i++)
    {
        string animal;
        fin >> animal >> k[i];
        for (int j = 0; j < k[i]; j++)
        {
            string c; fin >> c;
            int index = getIndex(characteristics, c, nc);
            if (index != -1)
            {
                is[i][index] = true;
            }
            else
            {
                characteristics[nc] = c;
                is[i][nc] = true;
                nc++;
            }
        }
    }
    
    int mostYes = 0;
    for (int an1 = 0; an1 < n-1; an1++)
    {
        //observation: at least two animals will always be in the set prior to determining the answer

        for (int an2 = an1+1; an2 < n; an2++)
        {
            int yes = 0;
            for(int c = 0; c < nc; c++)
            {
                if(!is[an1][c] || !is[an2][c]) continue;
                yes++;
            }
            mostYes = max(mostYes, yes);
        }
        //bad logic
        /*
          bool set[100]{}; bool newset[100]{}; for(int i = 0; i < 100; i++) set[i] = newset[i] = true;

        for (int c = 0; c < nc; c++)
        {
            if(!is[animal][c]) continue;
            
            for(int an = 0; an < n; an++)
                newset[an] = set[an] && is[an][c];
            
            bool unsure = false;
            for(int an = 0; an < n; an++)
            {
                if (an == animal) continue;
                unsure = unsure || newset[an];
            }
            
            if(unsure)
            {
                for (int i = 0; i < n; i++) set[i] = newset[i];
                yes++;
            }
        }*/
    }
    mostYes++;
    
    fout << mostYes << '\n';
    return 0;
}
