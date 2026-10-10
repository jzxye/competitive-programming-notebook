#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N_MAX = 50;
const int M_MAX = 50;
int n, m;
char maze[N_MAX][M_MAX];
bool visited[N_MAX][M_MAX];
vector<pair<int, int>> G;
vector<pair<int, int>> B;

void floodfill(int r, int c)
{
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || maze[r][c] == '#')
        return;
    
    visited[r][c] = true;

    floodfill(r-1, c);
    floodfill(r+1, c);
    floodfill(r, c+1);
    floodfill(r, c-1);
}

bool blockable(int r, int c)
{    
    // cout << "testing (" << r << ',' << c << ")" << '\n';
    if (r < 0 || r >= n || c < 0 || c >= m || visited[r][c])
        return true;
    
    visited[r][c] = true;
    if (maze[r][c] == 'G')
        return false;
    if (maze[r][c] != 'B'){
        // cout << "blocking (" << r << ',' << c << ")\n";
        maze[r][c] = '#';
        return true;
    }

    int ans = blockable(r + 1, c) && blockable(r - 1, c) && blockable(r, c + 1) && blockable(r, c - 1);
    return ans;
}

void solve()
{

    for (auto coords : B){
        if (!blockable(coords.first, coords.second)){
            cerr << "B unblockable" << '\n';
            cout << "No" << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = false;

    if (!G.empty() && maze[n-1][m-1] == '#'){
        cout << "No" << '\n';
        return;
    }

    floodfill(n - 1, m - 1);
    for (auto coords : G){
        if (!visited[coords.first][coords.second]){
            cerr << "G at (" << coords.first << ',' << coords.second << ") unreachable" << '\n';
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> maze[i][j];

        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < m; j++)
        //         cout << maze[i][j] << ' ';
        //     cout << '\n';
        // }

        for(int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                visited[i][j] = false;

        G.clear();
        B.clear();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (maze[i][j] == 'G')
                    G.push_back({i, j});
                else if (maze[i][j] == 'B')
                    B.push_back({i, j});

        // cout << "G coords: ";
        // for (auto coords : G)
        //     cout << coords.first << ',' << coords.second << ' ';
        // cout << '\n';
        // cout << "B coords: ";
        // for (auto coords : B)
        //     cout << coords.first << ',' << coords.second << ' ';
        // cout << '\n';
        
        // observation: if a bad person is blockable, then he is blockable by putting walls directly surrounding him
        //  so we just need to check if every good person is connected to the exit, and if every cell surrounding B sectors is '#' or '.'

        solve();
    }
}