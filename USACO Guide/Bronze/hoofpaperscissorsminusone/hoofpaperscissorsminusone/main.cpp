#include <iostream>
using namespace std;

int main()
{
    //Time complexity: O(N^2 + NM)
    int n, m; cin >> n >> m;
    char wld[3001][3001];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char c; cin >> c;
            wld[i][j] = c;
            if (c == 'W') wld[j][i] = 'L';
            else if (c == 'D') wld[j][i] = 'D';
            else if (c == 'L') wld[j][i] = 'W';
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        int s1, s2; cin >> s1 >> s2;
        
        int combinations = 0;
        int dominated = 0;
        for (int s = 1; s <= n; s++)
        {
            if (wld[s1][s] == 'L' && wld[s2][s] == 'L') dominated++;
        }
        combinations += 2 * dominated * n - dominated * dominated;
        /* The formula can be visualized through the following.
            You can also arrive at the formula through complimentary counting
                . + . . +
                + + + + +
                . + . . +
                . + . . +
                + + + + +
         */
        
        cout << combinations << '\n';
    }
    
    return 0;
}
