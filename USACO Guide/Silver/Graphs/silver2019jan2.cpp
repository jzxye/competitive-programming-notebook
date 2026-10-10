#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N_MAX = 1000;
int N; 
char grid[N_MAX][N_MAX];
bool visited[N_MAX][N_MAX];
int perimeter = 0;
int area = 0;

bool floodfill(int r, int c)
{
    if (r < 0 || r >= N || c < 0 || c >= N || grid[r][c] == '.')
        return false;
    else if (visited[r][c])
        return true;

    visited[r][c] = true;

    int neighbors = floodfill(r+1, c) + floodfill(r-1, c) + floodfill(r, c+1) + floodfill(r, c-1);

    perimeter += 4-neighbors;
    area++;
    return true;
}

int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    fin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> grid[i][j];

    int max_area = 0;
    int min_perimeter = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                floodfill(i,j);
                if (area >= max_area)
                {
                    min_perimeter = area == max_area ? min(min_perimeter, perimeter) : perimeter;
                    max_area = area;
                }
                area = 0;
                perimeter = 0;
            }
        }
    }

    fout << max_area << ' ' << min_perimeter << '\n';
}