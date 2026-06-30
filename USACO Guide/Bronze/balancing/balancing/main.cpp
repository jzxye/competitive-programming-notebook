#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
using namespace std;

/*struct coord
{
    int x;
    int y;
};
bool compX(coord p1, coord p2)
{
    return p1.x < p2.x;
}

bool compY(coord p1, coord p2)
{
    return p1.y < p2.y;
}

int main()  //O(N^2)
{
    ifstream fin ("balancing.in");
    ofstream fout ("balancing.out");
    
    // n <= 100
    int n, b; fin >> n >> b;
    coord posbyx[100]; coord posbyy[100];
    for (int i = 0; i < n; i++)
    {
        int x, y; fin >> x >> y;
        posbyx[i].x = posbyy[i].x = x;
        posbyx[i].y = posbyy[i].y = y;
    }
    
    sort(posbyx, posbyx + n, compX);
    sort(posbyy, posbyy + n, compY);
    
    
    int m = INT_MAX;
    
    for (int xi = 0; xi < n; xi++)
    {
        int q[4]{};
        if (xi < n-1 && posbyx[xi].x == posbyx[xi+1].x) continue;
        q[1] = xi+1;
        q[0] = n-xi-1;
        
        int yl = 0;
        int yu = 0;
        for (;;)
        {
            while(yu < n-1 && posbyy[yu].y == posbyy[yu+1].y) yu++;
            
            int a = posbyx[xi].x + 1;
          //  int b = posbyy[yu].y + 1;
            
            for (int i = yl; i <= yu; i++)
            {
                if(posbyy[i].x < a)
                {
                    q[1]--;
                    q[2]++;
                }
                else if(posbyy[i].x > a)
                {
                    q[0]--;
                    q[3]++;
                }
            }
            
            m = min(m, max(max(max(q[0], q[1]), q[2]), q[3]));
            
            yu++; if (yu == n) break;
            yl = yu;
        }

    }
    
    fout << m << '\n';
    
    return 0;
}
*/
