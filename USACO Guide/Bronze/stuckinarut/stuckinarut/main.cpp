#include <iostream>
#include <climits>
using namespace std;

struct pos
{
    int x;
    int y;
};

int main()
{
    int n; cin >> n;
    
    pos start[50];
    pos end[50];
    int grass[50]{};
    
    
    int north[50]; //index of cows from left to right
    int east[50]; //bottom up
    int nn = 0;
    int ne = 0;
    
    for (int i = 0; i < n; i++)
    {
        char dir; int x, y;
        cin >> dir >> x >> y;
        
        start[i].x = end[i].x = x;
        start[i].y = end[i].y = y;
        
        if (dir == 'N')
        {
            end[i].y = INT_MAX;
            north[nn] = i;
            nn++;
        }
        else
        {
            end[i].x = INT_MAX;
            east[ne] = i;
            ne++;
        }
    }
    
    //sort north and east
    for (int i = 0; i < nn - 1; i++)
    {
        int x_min = start[north[i]].x;
        int index = i;
        for (int j = i+1; j < nn; j++)
        {
            if (start[north[j]].x < x_min)
            {
                x_min = start[north[j]].x;
                index = j;
            }
            else if (start[north[j]].x == x_min)
            {
                if (start[north[j]].y > start[north[index]].y)
                    index = j;
            }
        }
        
        int temp = north[i];
        north[i] = north[index];
        north[index] = temp;
        
    }
    for (int i = 0; i < ne - 1; i++)
    {
        int y_min = start[east[i]].y;
        int index = i;
        for (int j = i+1; j < ne; j++)
        {
            if (start[east[j]].y < y_min)
            {
                y_min = start[east[j]].y;
                index = j;
            }
            else if (start[east[j]].y == y_min)
            {
                if (start[east[j]].x > start[east[index]].x)
                    index = j;
            }
        }
        
        int temp = east[i];
        east[i] = east[index];
        east[index] = temp;
        
    }

    
    //ALL X AND Y VALUES ARE DISTINCT
/*    for (int i = 0; i < nn - 1; i++)
    {
        for (int j = i+1; j < nn; j++)
        {
            if (start[north[i]].x == start[north[j]].x)
            {
                if (start[north[i]].y < start[north[j]].y)
                {
                    grass[north[i]] = start[north[j]].y - start[north[i]].y;
                    end[north[i]].y = start[north[j]].y;
                }
                else if (start[north[i]].y > start[north[j]].y)
                {
                    grass[north[j]] = start[north[i]].y - start[north[j]].y;
                    end[north[j]].y = start[north[i]].y;
                }
            }
        }
    }
    for (int i = 0; i < ne - 1; i++)
    {
        for (int j = i+1; j < ne; j++)
        {
            if (start[east[i]].y == start[east[j]].y)
            {
                if (start[east[i]].x < start[east[j]].x)
                {
                    grass[east[i]] = start[east[j]].x - start[east[i]].x;
                    end[east[i]].x = start[east[j]].x;
                }
                else if (start[east[i]].x > start[east[j]].x)
                {
                    grass[east[j]] = start[east[i]].x - start[east[j]].x;
                    end[east[j]].x = start[east[i]].x;
                }
            }
        }
    }*/

    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < ne; j++)
        {
            int n = north[i];
            int e = east[j];
            if(start[e].y >= start[n].y && start[e].x <= start[n].x)
            {
                if(grass[e] == 0 && start[n].x - start[e].x > start[e].y - start[n].y && start[e].y < end[n].y)
                {
                    grass[e] = start[n].x - start[e].x;
                    end[e].x = start[n].x;
                }
                else if (start[n].x - start[e].x < start[e].y - start[n].y && start[n].x < end[e].x)
                {
                    grass[n] = start[e].y - start[n].y;
                    end[n].y = min(end[n].y, start[e].y);
                    break;
                }
            }
        }
    }
    
    
    for (int i = 0; i < n; i++)
    {
        if (grass[i] == 0) cout << "Infinity" << '\n';
        else cout << grass[i] << '\n';
    }
    
    
    return 0;
    
}




//MISREAD PROBLEM STATEMENT (only N and E)

/*


bool perpendicular (char dir1, char dir2)
{
    return (dir1 == 'N' && dir2 == 'E') || (dir1 == 'N' && dir2 == 'W')
        || (dir1 == 'S' && dir2 == 'E') || (dir1 == 'S' && dir2 == 'W')
        || (dir1 == 'E' && dir2 == 'N') || (dir1 == 'E' && dir2 == 'N')
        || (dir1 == 'W' && dir2 == 'S') || (dir1 == 'W' && dir2 == 'S');
}

int main()
{
    int n; cin >> n;
    
    int grass[50]{};
    pos start[50];
    pos curr[50];
    bool done[50]{};
    char dir[50];
    int x_max, x_min, y_max, y_min; x_max = y_max = INT_MIN; x_min = y_min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        char diri; int xi, yi; cin >> diri >> xi >> yi;

        start[i].x = curr[i].x = xi;
        start[i].y = curr[i].y = yi;
        dir[i] = diri;
        
        if (diri == 'N' || diri == 'S')
        {
            x_max = max(x_max, xi);
            x_min = min(x_min, xi);
        }
        else
        {
            y_max = max(y_max, yi);
            y_min = min(y_min, yi);
        }
        
    }
    
    for (;;)
    {
        //eat
        for (int i = 0; i < n; i++)
            if(!done[i]) grass[i]++;
        
        //move
        for (int i = 0; i < n; i++)
        {
            if(!done[i])
            {
                switch(dir[i])
                {
                    case 'N':
                        curr[i].y++;
                        break;
                    case 'E':
                        curr[i].x++;
                        break;
                    case 'S':
                        curr[i].y--;
                        break;
                    case 'W':
                        curr[i].x--;
                        break;
                }
            }
        }
        
        //check if cows are done
        for (int i = 0; i < n; i++)
        {
            if ((dir[i] == 'E' && curr[i].x > x_max) || (dir[i] == 'W' && curr[i].x < x_min)
                || (dir[i] == 'N' && curr[i].y > y_max) || (dir[i] == 'S' && curr[i].y < y_min))
            {
                grass[i] = -1;
                done[i] = true;
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (perpendicular(dir[i], dir[j]))
                    {
                        if (curr[i].y == curr[j].y)
                        {
                            if((start[j].x <= curr[i].x && curr[i].x < curr[j].x)
                               || (curr[j].x < curr[i].x && curr[i].x <= start[j].x))
                                done[i] = true;
                        }
                        else if (curr[i].x == curr[j].x)
                        {
                            if((start[j].y <= curr[i].y && curr[i].y < curr[j].y)
                               || (curr[j].y < curr[i].y && curr[i].y <= start[j].y))
                                done[i] = true;
                        }
                    }
                }
            }
        }
        
        //if all done, break
        bool alldone = true;
        for (int i = 0; i < n; i++)
            alldone = alldone && done[i];
        if(alldone) break;
    }

    for (int i = 0; i < n; i++)
    {
        if(grass[i] == -1) cout << "Infinity" << '\n';
        else cout << grass[i] << '\n';
    }
    
    return 0;
}
*/
