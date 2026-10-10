#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int R_MAX = 500;
const int C_MAX = 500;
const int U_MAX = 100000;

int R;
int C;

char image[R_MAX+1][C_MAX+1];
bool sweden[R_MAX+1][C_MAX+1];

const pair<int,int> DIR[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int floodfill(int r, int c)
{
    if (r < 1 || r > R || c < 1 || c > C || sweden[r][c] || image[r][c] == '.')
        return 0;

    sweden[r][c] = true;
    
    int curr = 1;

    for (int i = 0; i < 4; i++){
        int x = r+DIR[i].first;
        int y = c+DIR[i].second;
        curr += floodfill(x,y);
    }

    return curr;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int U; cin >> R >> C >> U;

    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            cin >> image[i][j];

    int s_r;
    int s_c;
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            if (image[i][j] == 'S'){
                s_r = i;
                s_c = j;
            }

    int landmass = floodfill(s_r, s_c);
    cout << landmass << '\n';

    while (U--)
    {
        int r, c; cin >> r >> c;
        image[r][c] = '#';
        
        for(int i = 0; i < 4; i++){
            int x = r + DIR[i].first;
            int y = c + DIR[i].second;
            if (1<= x && x <= R && 1 <= y && y <= C && sweden[x][y]){
                landmass += floodfill(r,c);
                break;
            }
        }

        cout << landmass << '\n';
    }
}