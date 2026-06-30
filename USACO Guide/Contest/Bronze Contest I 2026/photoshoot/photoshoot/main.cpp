#include <iostream>
using namespace std;

const int NMAX = 500;

int main()
{
    int N, K; cin >> N >> K;
    
    int Q; cin >> Q;
    
    int beauty[NMAX+1][NMAX+1]{};
    int attractiveness[NMAX+1][NMAX+1]{};  //r, c should not exceed N-K+1
    
    int maxAttractiveness = 0;
    
    //Time Complexity O(Q * N^2)
    for (int q = 0; q < Q; q++)
    {
        int r, c, v; cin >> r >> c >> v;
        
        for (int row = max(1, r-K+1); row <= r; row++)
        {
            for (int col = max(1, c-K+1); col <= c; col++)
            {
                if (beauty[r][c] != 0) attractiveness[row][col] -= beauty[r][c];
                attractiveness[row][col] += v;
            }
        }
        beauty[r][c] = v;
        
        for (int row = max(1, r-K+1); row <= r; row++)
            for (int col = max(1, c-K+1); col <= c; col++)
                maxAttractiveness = max(maxAttractiveness, attractiveness[row][col]);
            
        cout << maxAttractiveness << '\n';
        
    }
    return 0;
}
