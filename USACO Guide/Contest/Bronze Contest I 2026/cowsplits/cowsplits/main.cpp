#include <iostream>
#include <string>
using namespace std;

const int NMAX = 100000;
int counter[3];
int N;

bool findT(string condensed, char ignore, int &M, int steps[])
{
    string T;
    bool included[NMAX]{};
    for (int i = 0; i < condensed.size(); i++)
    {
        if (condensed[i] != ignore)
        {
            T += condensed[i];
            included[i] = true;
        }
    }
    
    if (T.substr(0, T.size()/2) == T.substr(T.size()/2, T.size()/2))
    {
        M++;
        for (int i = 0; i < N; i++)
        {
            if(included[i])
            {
                steps[3*i] = M;
                steps[3*i + 1] = M;
                steps[3*i + 2] = M;
            }
        }
        return true;
    }
    return false;
}

bool findT2(string condensed, char ignore, int &M, int steps[])
{
    string T;
    bool included[NMAX]{};
    for (int i = 0; i < condensed.size(); i++)
    {
        if (condensed[i] != ignore)
        {
            T += condensed[i];
            included[i] = true;
        }
    }
    
    if (T.substr(0, T.size()/2) == T.substr(T.size()/2, T.size()/2))
    {
        M++;
        for (int i = 0; i < N; i++)
        {
            if(included[i])
            {
                steps[3*i] = M;
                steps[3*i + 1] = M;
                steps[3*i + 2] = M;
            }
        }
        return true;
    }
    return false;
}
bool allEven(int a, int b, int c)
{
    return a%2 == 0 && b%2 == 0 && c%2==0;
}
void replace(string condensed, char c, int &M, int steps[])
{
    M++;
    for (int i = 0; i < N; i++)
        if(condensed[i] == c)
           steps[3*i] = steps[3*i+1] = steps[3*i+2] = M;
}
void replaceExclusive(string condensed, char c, int &M, int steps[], bool excluded[])
{
    M++;
    for (int i = 0; i < N; i++)
        if(condensed[i] == c && !excluded[i])
           steps[3*i] = steps[3*i+1] = steps[3*i+2] = M;
}

void replaceExcluded(string condensed, bool excluded[], int steps[], int &M)
{
    int i1 = 0;
    while (!excluded[i1]) i1++;
    int i2 = i1+1;
    while (!excluded[i2]) i2++;
    
    if ((condensed[i1]-'1'+1) % 3 == condensed[i2]-'1')
    {
        M++;
        steps[i1+1] = steps[i1+2] = steps[i2] = steps[i2+1] = M;
        M++;
        steps[i1] = steps[i2+2] = M;
    }
    else
    {
        M++;
        steps[i1] = steps[i1+1] = steps[i2+1] = steps[i2+2] = M;
        M++;
        steps[i1+2] = steps[i2] = M;
    }
}
int main()
{
    int T, k; cin >> T >> k;
    
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        string s; cin >> s;
        
        if (N % 2 == 1)
        {
            cout << -1 << '\n';
            continue;
        }
        
        string condensed;
        for (int i = 0; i < N; i++)
        {
            string cow = s.substr(3 * i, 3);
            if (cow == "COW")
                condensed += '1';
            else if (cow == "OWC")
                condensed += '2';
            else if (cow == "WCO")
                condensed += '3';
            
            counter[condensed[i]-'1']++;
        }
        
        // COW OWC WCO
        //X is square := X = Y + Y
        
        //observation: a square sequence has an even number of O's W's and C's
        //              each cyclical orientation of COW only has one of each
        //              N must be even for valid sequences
        //observation: since all ordered pairs of COW, OWC, WCO can be eliminated in <= 2 moves, ALL even sequences are valid
        
        //assign 1 = COW, 2 = OWC, 3 = WCO
        /*ex. 1111223212312123
         
         1(3)2(2)3123
         (11123221)
         (21122311)
         (11131322)
         (11321132) T 1st half has same count 1,2,3 as 2nd half
         (11311322)
         
         13131 2 1131
         observation: if there is an even number of 1, 2, or 3, they can be removed with one move
         observation: for square sequence, 1st half has same count of 1,2,3 as 2nd half
         
         case 1: even + even + even = even (3 moves max) (1 move min)
         
         case 2: even + odd + odd = even (5 moves max) (3 moves min)
         - take one from each odd group. these will be removed in two moves at the end.
         -
         
         WCOCOWWCOCOW (3131)
         COWCOWOWCOWCOWCOWC (112222)
         
         
         */
        
        int M = 0;
        int steps[3*NMAX]{};
        
        //even even even
        if (allEven(counter[0], counter[1], counter[2]))
        {
            if(findT(condensed, '0', M, steps))
            {}
            else
            {
                if(findT(condensed, '1', M, steps))
                    replace(condensed, '1', M, steps);
                else if (findT(condensed, '2', M, steps))
                    replace(condensed, '2', M, steps);
                else if (findT(condensed, '3', M, steps))
                    replace(condensed, '3', M, steps);
                else
                {
                    replace(condensed, '1', M, steps);
                    replace(condensed, '2', M, steps);
                    replace(condensed, '3', M, steps);
                }
            }
        }
        else
        //even odd odd
        {
            if(counter[0] % 2 == 0)
            {
                bool excluded[NMAX]{};
                int i = 0;
                while (condensed[i] != '2') i++;
                excluded[i] = true;
                i = 0;
                while (condensed[i] != '3') i++;
                excluded[i] = true;
                replaceExclusive(condensed, '1', M, steps, excluded);
                replaceExclusive(condensed, '2', M, steps, excluded);
                replaceExclusive(condensed, '3', M, steps, excluded);
                replaceExcluded(condensed, excluded, steps, M);
            }
            else if (counter[1] % 2 == 0)
            {
                bool excluded[NMAX]{};
                int i = 0;
                while (condensed[i] != '1') i++;
                excluded[i] = true;
                i = 0;
                while (condensed[i] != '3') i++;
                excluded[i] = true;
                replaceExclusive(condensed, '1', M, steps, excluded);
                replaceExclusive(condensed, '2', M, steps, excluded);
                replaceExclusive(condensed, '3', M, steps, excluded);
                replaceExcluded(condensed, excluded, steps, M);
            }
            else if (counter[2] % 2 == 0)
            {
                bool excluded[NMAX]{};
                int i = 0;
                while (condensed[i] != '2') i++;
                excluded[i] = true;
                i = 0;
                while (condensed[i] != '1') i++;
                excluded[i] = true;
                replaceExclusive(condensed, '1', M, steps, excluded);
                replaceExclusive(condensed, '2', M, steps, excluded);
                replaceExclusive(condensed, '3', M, steps, excluded);
                replaceExcluded(condensed, excluded, steps, M);
            }
        }
        cout << M << '\n';
        cout << steps[0];
        for (int i = 1; i < 3*N; i++)
            cout << ' ' << steps[i];
        cout << '\n';
        
    }
    return 0;
}
