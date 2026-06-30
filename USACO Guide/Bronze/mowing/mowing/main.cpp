#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

struct pos
{
    int x;
    int y;
};
int main()
{
    ifstream fin ("mowing.in");
    ofstream fout ("mowing.out");
    
    int n; fin >> n;
    
    int timeGrid[1001][1001];
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            timeGrid[i][j] = -1;
    timeGrid[0][0] = 0;
    
    pos p; p.x = p.y = 0;
    int time = 0;
    int x = INT_MAX;
    
    for (int i = 0; i < n; i++)
    {
        char dir; fin >> dir;
        int steps; fin >> steps;
        
        for (int j = 0; j < steps; j++)
        {
            time++;
            switch(dir)
            {
                case 'N':
                    p.y++;
                    break;
                case 'E':
                    p.x++;
                    break;
                case 'S':
                    p.y--;
                    break;
                case 'W':
                    p.x--;
                    break;
            }
            if (timeGrid[(p.x + 1001) % 1001][(p.y + 1001) % 1001] != -1)
                x = min(x, time - timeGrid[(p.x + 1001) % 1001][(p.y + 1001) % 1001]);
            
            timeGrid[(p.x + 1001) % 1001][(p.y + 1001) % 1001] = time;
        }
    }
    
    if (x == INT_MAX) x = -1;
    fout << x << '\n';
        
    return 0;
}
