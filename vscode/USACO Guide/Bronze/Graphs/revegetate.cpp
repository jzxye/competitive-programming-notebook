#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


const int NMAX = 100;

int main()
{
    ifstream fin ("revegetate.in");
    ofstream fout ("revegetate.out");
    int N, M; fin >> N >> M;

    //each cow is an edge
    //the two nodes must be 'colored' differently
    //the problem specifies each node only has 3 edges, guaranteeing a possible coloring with 4 colors
    bool graph[NMAX+1][NMAX+1]{}; 
    for (int i = 0; i < M; i++)
    {
        int x, y; fin >> x >> y;
        graph[x][y] = graph[y][x] = true;
    }

    int colors[NMAX+1]; for (int i = 1; i <= N; i++) colors[i] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j) continue;
            if (!graph[i][j]) continue;
            
            if(colors[i] == colors[j]) 
            {
                if( i < j)
                    colors[j]++;
                else 
                    colors[i]++;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        char c = '0' + colors[i];
        fout << c;
    }
    fout << '\n';
    
    return 0;
}