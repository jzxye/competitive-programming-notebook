#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N_MAX = 1000;
const int M_MAX = 1000;
int n, m;
char grid[N_MAX][M_MAX]{};
bool visited[N_MAX][M_MAX]{};

void floodfill(int r, int c)
{
    if (!(0 <= r && r < n && 0 <= c && c < m
        && !visited[r][c] && grid[r][c] != '#'))
        return;

    visited[r][c] = true;

    floodfill(r-1, c);
    floodfill(r+1, c);
    floodfill(r, c-1);
    floodfill(r, c+1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    int rooms = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != '#' && !visited[i][j])
            {
                floodfill(i, j);
                rooms++;
            }
        }
    }

    cout << rooms << '\n';

}