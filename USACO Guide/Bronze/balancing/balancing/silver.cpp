#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
using namespace std;

const int NMAX = 1000;

struct coord
{
    int x, y;
    
    coord() {}
    
    coord(int x, int y)
    : x(x), y(y){}
};

bool sortbyx(coord c1, coord c2)
{
    return c1.x < c2.x;
}
bool sortbyy(coord c1, coord c2)
{
    return c1.y < c2.y;
}

int main() 
{
    //in general, it is not true that in the optimal configuration, x = a splits the points as evenly as possible
    // likewise it is not always true that y = b splits the points as evenly as possible
    //Ex. 3 4    vs     5 2
    //    3 4           2 5
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    
    int N; fin >> N;
    coord cows[NMAX];
    coord cowsX[NMAX];
    coord cowsY[NMAX];
    
    for (int i = 0; i < N; i++)
    {
        int x, y; fin >> x >> y;
        cows[i] = cowsX[i] = cowsY[i] = coord(x, y);
    }
    sort(cowsX, cowsX+N, sortbyx);
    sort(cowsY, cowsY+N, sortbyy);
    
    int q1, q2, q3, q4;
    q1 = N;
    q2 = q3 = q4 = 0;
    
    int m = N;
    
    for (int i = 0; i < N; i++)
    {
        q1--; q2++;
        q1 += q4; q4 = 0;
        q2 += q3; q3 = 0;
        if (i+1 < N && cowsX[i].x == cowsX[i+1].x) continue;
        
        int a = cowsX[i].x + 1;
        
        for (int j = 0; j < N; j++)
        {
            if (cowsY[j].x < a)
            {
                q2--;
                q3++;
            }
            else
            {
                q1--;
                q4++;
            }
            
            if (j+1 < N && cowsY[j].y == cowsY[j+1].y) continue;
            
            m = min(m, max(q1, max(q2, max(q3, q4))));
        }
    }
    
    fout << m << '\n';
    return 0;
}
