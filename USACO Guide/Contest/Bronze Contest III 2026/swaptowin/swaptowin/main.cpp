#include <iostream>
#include <string>
#include <utility>
using namespace std;

const int NMAX = 1000;
const int MMAX = 1000;

int main()
{
    // O(TNM)
    
    int T; cin >> T;
    
    while (T--)
    {
        int N, M; cin >> N >> M;
        string t; cin >> t; t = " " + t;
        string s[NMAX+1];
        int letterCount[NMAX+1][26]{};
        
        for (int i = 1; i <= N; i++)
        {
            cin >> s[i]; s[i] = " " + s[i];
            for (int c = 1; c <= M; c++)
                letterCount[i][s[i][c]-'a']++;
        }
        
        
        int K = 0; // K <= 2M
        int operations[2*MMAX][4];
        //operations
        //𝟷 𝚡 𝚙 𝚚
        //𝟸 𝚡 𝚢 𝚔
        
        bool used[NMAX+1][MMAX+1]{};
        int neededat[NMAX+1][MMAX+1]{};
        
        for (int i = 1; i <= M; i++)
        {
            char letter = t[i];
            for (int j = 1; j <= N; j++)
            {
                if (letterCount[j][letter-'a'])
                {
                    letterCount[j][letter-'a']--;
                    for(int k = 1; k <= M; k++)
                    {
                        if(s[j][k] == letter && !used[j][k])
                        {
                            used[j][k] = true;
                            neededat[j][k] = i;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        
       /* for (int i = 1; i<= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                cout << neededat[i][j];
            }
            cout << '\n';
        }*/

        //swaps
        
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
            {
                if(!neededat[i][j] ) continue;
                
                int k = neededat[i][j];
                //operation 1
                neededat[i][j] = 0;
                
                if (j != k)
                {
                    operations[K][0] = 1;
                    operations[K][1] = i;
                    operations[K][2] = j;
                    operations[K][3] = k;
                    K++;
                    swap(neededat[i][j], neededat[i][k]);
                    //neededat[i][j] = neededat[i][k];
                    //neededat[i][k] = 0;
                }
                //operation 2
                if( i != 1)
                {
                    operations[K][0] = 2;
                    operations[K][1] = 1;
                    operations[K][2] = i;
                    operations[K][3] = k;
                    swap(neededat[i][k], neededat[1][k]);
                    //neededat[i][j] = 0;
                    K++;
                }
                
                //neededat[i][j] = 0;
                --j; //in case an important letter swapped into this position
            }
        }
        

        
        
        
        
       /* //operation 2 first
        for (int i = 1; i <= M; i++)
        {
            if (s[1][i] == t[i]) continue;
            
            for (int j = 2; j <= N; j++)
            {
                if (t[i] == s[j][i])
                {
                    operations[K][0] = 2;
                    operations[K][1] = 1;
                    operations[K][2] = j;
                    operations[K][3] = i;
                    K++;
                    swap(s[1][i], s[j][i]);
                    break;
                }
            }
        }
        
        //operation 1
        for (int i = 1; i <= M; i++)
        {
            if (s[1][i] == t[i]) continue;
            
            for (int x = 1; x <= N; x++)
            {
                if(s[1][i] == t[i]) break;

                for (int j = 1; j <= M; j++)
                {
                    if (s[x][j] == t[i])
                    {
                        if(i != j)
                        {
                            operations[K][0] = 1;
                            operations[K][1] = x;
                            operations[K][2] = i;
                            operations[K][3] = j;
                            K++;
                            swap(s[x][i], s[x][j]);
                        }
                        
                        operations[K][0] = 2;
                        operations[K][1] = 1;
                        operations[K][2] = x;
                        operations[K][3] = i;
                        K++;
                        swap(s[1][i], s[x][i]);
                        
                        break;
                    }
                }
            }
        }*/
        
        
        //print
        cout << K << '\n';
        for (int i = 0; i < K; i++)
        {
            cout << operations[i][0] << " " << operations[i][1] << " " << operations[i][2] << " " << operations[i][3] << '\n';
        }
    }

    return 0;
}
