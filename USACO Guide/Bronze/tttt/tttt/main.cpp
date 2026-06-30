#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ifstream inf ("tttt.in");
    ofstream outf ("tttt.out");
    
    //M1: No Sets
   /* char board[3][3];
    bool playing[26]{};
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            inf >> board[i][j];
            playing[board[i][j] - 'A'] = true;
        }
    
    char rcd[8][3]; //rows, cols, diagonals
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            rcd[i][j] = board[i][j];
            rcd[i+3][j] = board[j][i];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        rcd[6][i] = board[i][i];
        rcd[7][i] = board[2-i][i];
    }
    
    
    
    bool wins[26][26]{};
    for (int i = 0; i < 8; i++)
    {
        if (rcd[i][0] == rcd[i][1] && rcd[i][1] == rcd[i][2])
            wins[rcd[i][0] - 'A'][rcd[i][0] - 'A'] = true;
        else
        {
            bool letters[26]{};
            
            for (int j = 0; j < 3; j++)
                letters[rcd[i][j] - 'A'] = true;
            
            int count = 0;
            for (int letter = 0; letter < 26; letter++)
                if (letters[letter]) count++;
            
            if (count == 2)
            {
                int i = 0; while (!letters[i]) i++;
                int j = i+1; while (!letters[j]) j++;
                wins[i][j] = true;
            }
        }
    }

    int soloWins = 0;
    int duoWins = 0;
    
    for (int i = 0; i < 26; i++)
        if (wins[i][i]) soloWins++;
    
    for (int i = 0; i < 25; i++)
        for (int j = i+1; j < 26; j++)
            if (wins[i][j]) duoWins++;*/
    
    
    //M2: Sets
    set<set<char>> rcd;
    char board[3][3];
    
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            inf >> board[r][c];

    for (int r = 0; r < 3; r++)
    {
        set<char> row;
        for (int c = 0; c < 3; c++)
            row.insert(board[r][c]);
        rcd.insert(row);
    }
    for (int c = 0; c < 3; c++)
    {
        set<char> col;
        for (int r = 0; r < 3; r++)
            col.insert(board[r][c]);
        rcd.insert(col);
    }
    for(int d = 0; d < 2; d++)
    {
        set<char> diag1, diag2;
        for(int rc = 0; rc < 3; rc++)
        {
            diag1.insert(board[rc][rc]);
            diag2.insert(board[rc][2-rc]);
        }
        rcd.insert(diag1);
        rcd.insert(diag2);
    }

    int one = 0;
    int two = 0;
    for (const set<char> &s : rcd)
    {
        if(s.size() == 1) one++;
        else if(s.size() == 2) two++;
    }
    outf << one << '\n';
    outf << two << '\n';

    
  /*  //rows
    for (int i = 0; i < 3; i++)
    {
        bool letters[26]{};
        
        for (int j = 0; j < 3; j++)
        {
            letters[board[i][j] - 'A'] = true;
        }
        
        int count = 0;
        for (int letter = 0; letter < 26; letter++)
            if (letters[letter]) count++;

        if (count == 1) soloWins++;
        else if (count == 2) duoWins++;
    }
    
    //columns
    for (int i = 0; i < 3; i++)
    {
        bool letters[26]{};

        for (int j = 0; j < 3; j++)
        {
            letters[board[j][i] - 'A'] = true;
        }
        
        int count = 0;
        for (int letter = 0; letter < 26; letter++)
            if (letters[letter]) count++;
        
        if (count == 1) soloWins++;
        else if (count == 2) duoWins++;
    }
    
    //diagonals
    int count = 0;
    bool letters[26]{};
    for (int i = 0; i < 3; i++)
    {
        letters[board[i][i] - 'A'] = true;
    }
    for (int letter = 0; letter < 26; letter++)
        if (letters[letter]) count++;
    
    if (count == 1) soloWins++;
    if (count == 2) duoWins++;
    
    count = 0;
    for (int i = 0; i < 26; i++) letters[i] = false;
    for (int i = 0; i < 3; i++)
    {
        letters[board[2-i][i] - 'A'] = true;
    }
    for (int letter = 0; letter < 26; letter++)
        if (letters[letter]) count++;
    if (count == 1) soloWins++;
    if (count == 2) duoWins++;
    
    outf << soloWins << '\n';
    outf << duoWins << '\n';*/
    
    return 0;
}
