#include <iostream>
#include <fstream>
#include <utility>
#include <climits>
using namespace std;

const int NMAX = 8;
const int KMAX = 10;
int N, K;
bool figure[NMAX][NMAX]{};
bool pieces[KMAX][NMAX][NMAX]{};

struct coord
{
    int x, y;
    
    coord(int x, int y)
    :x(x), y(y) {}
};

bool search(int k1, int k2, ofstream& fout)
{
    coord ul1(NMAX, NMAX);
    coord br1(-1, -1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!pieces[k1][i][j]) continue;
            
            ul1.x = min(ul1.x, i);
            ul1.y = min(ul1.y, j);
            br1.x = max(br1.x, i);
            br1.y = max(br1.y, j);
        }
    }
    int l1 = br1.x - ul1.x + 1;
    int w1 = br1.y - ul1.y + 1;
    
    coord ul2(NMAX, NMAX);
    coord br2(-1, -1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!pieces[k2][i][j]) continue;
            
            ul2.x = min(ul2.x, i);
            ul2.y = min(ul2.y, j);
            br2.x = max(br2.x, i);
            br2.y = max(br2.y, j);
        }
    }
    int l2 = br2.x - ul2.x + 1;
    int w2 = br2.y - ul2.y + 1;
    
 /*   cout << '(' << ul1.x << ',' << ul1.y << ')' <<'\n';
    cout << '(' << br1.x << ',' << br1.y << ')' <<'\n';
    cout << '(' << ul2.x << ',' << ul2.y << ')' <<'\n';
    cout << '(' << br2.x << ',' << br2.y << ')' <<'\n';
    cout << l1 << " by " << w1 << '\n';
    cout << l2 << " by " << w2 << '\n';*/
    
    for (int x1 = 0; x1 <= N - l1; x1++)
    {
        for (int y1 = 0; y1 <= N - w1; y1++)
        {
            for (int x2 = 0; x2 <= N - l2; x2++)
            {
                for (int y2 = 0; y2 <= N - w2; y2++)
                {
                    bool reconstructed[NMAX][NMAX]{};
                    for (int i = 0; i < l1; i++)
                        for (int j = 0; j < w1; j++)
                            reconstructed[x1+i][y1+j] = pieces[k1][ul1.x+i][ul1.y+j];
                    
                    for (int i = 0; i < l2; i++)
                        for (int j = 0; j < w2; j++)
                            reconstructed[x2+i][y2+j] |= pieces[k2][ul2.x+i][ul2.y+j];
                    
                    bool valid = true;
                    for (int i = 0; i < N; i++)
                        for (int j = 0; j < N; j++)
                            valid &= reconstructed[i][j] == figure[i][j];
                    
                  /*  //PRINT
                    for (int i = 0; i < N; i++)
                    {
                        for (int j = 0; j < N; j++)
                            cout << reconstructed[i][j];
                        cout << '\n';
                    }
                    cout << '\n';*/
                    
                    if(valid)
                    {
                        fout << k1+1 << ' ' << k2+1 << '\n';
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    ifstream fin ("bcs.in");
    ofstream fout ("bcs.out");
    
    fin >> N >> K;
    
    //true means there is glass
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c; fin >> c;
            figure[i][j] = c == '#';
        }
    }
    
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                char c; fin >> c;
                pieces[i][j][k] = c == '#';
            }
        }
    }

    for (int k1 = 0; k1 < K-1; k1++)
    {
        for (int k2 = k1+1; k2 < K; k2++)
        {
            if (search(k1,k2,fout)) return 0;
        }
    }
    
    return 0;
}
