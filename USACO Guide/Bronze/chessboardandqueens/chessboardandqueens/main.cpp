#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool columnsOccupied[8]{};
vector<int> qCols;
int queens(bool board [][8])
{
    if (qCols.size() == 8)
    {
        //check diagonals and reserved squares
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (board[i][j] && qCols[i] == j) return 0;
        
        for (int r1 = 0; r1 < 7; r1++)
            for (int r2 = r1+1; r2 < 8; r2++)
                if (abs(r1 - r2) == abs(qCols[r1] - qCols[r2])) return 0;
        
        return 1;
    }
    
    int count = 0;
    for (int c = 0; c < 8; c++)
    {
        if(columnsOccupied[c]) continue;
        
        qCols.push_back(c);
        columnsOccupied[c] = true;
        count += queens(board);
        qCols.pop_back();
        columnsOccupied[c] = false;
    }
    
    return count;
}
int main()
{
    bool board[8][8]{};
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            char c; cin >> c;
            board[i][j] = c == '*';
        }
    
    cout << queens(board) << '\n';
    return 0;
}
