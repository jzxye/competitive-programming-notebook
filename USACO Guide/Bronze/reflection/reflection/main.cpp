#include <iostream>
using namespace std;

int main()
{
    int n, u; cin >> n >> u;
    
    bool canvas[2000][2000]; //true: painted, false: not painted
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            char c; cin >> c;
            canvas[i][j] = (c == '#');
        }
    

  /*  int r, c; r = c = -1;
    do
    {
        if (r != -1 && c != -1) canvas[r-1][c-1] = !canvas[r-1][c-1];
        
        int operations = 0;
        for (int i = 0; i < n/2; i++)
        {
            for (int j = 0; j < n/2; j++)
            {
                int changes = (canvas[i][j] ? 1:0) + (canvas[n-1-i][j] ? 1:0)
                                + (canvas[i][n-1-j] ? 1:0) + (canvas[n-1-i][n-1-j] ? 1:0);
                operations += min(changes, 4-changes);
            }
        }
        cout << operations << '\n';
    }while (cin >> r >> c);*/
    
    int operations = 0;
    for (int i = 0; i < n/2; i++)
    {
        for (int j = 0; j < n/2; j++)
        {
            int changes = (canvas[i][j] ? 1:0) + (canvas[n-1-i][j] ? 1:0)
                            + (canvas[i][n-1-j] ? 1:0) + (canvas[n-1-i][n-1-j] ? 1:0);
            operations += min(changes, 4-changes);
        }
    }
    cout << operations << '\n';
    
    
    for (int i = 0; i < u; i++)
    {
        int r, c; cin >> r >> c;
        
        int changes = (canvas[r-1][c-1] ? 1:0) + (canvas[n-1-(r-1)][c-1] ? 1:0)
                        + (canvas[r-1][n-1-(c-1)] ? 1:0) + (canvas[n-1-(r-1)][n-1-(c-1)] ? 1:0);
        operations -= min(changes, 4-changes);
        
        canvas[r-1][c-1] = !canvas[r-1][c-1];
        
        changes = (canvas[r-1][c-1] ? 1:0) + (canvas[n-1-(r-1)][c-1] ? 1:0)
                        + (canvas[r-1][n-1-(c-1)] ? 1:0) + (canvas[n-1-(r-1)][n-1-(c-1)] ? 1:0);
        operations += min(changes, 4-changes);
        
        cout << operations << '\n';
        
    }

        
    return 0;
}
