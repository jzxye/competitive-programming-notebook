/*
ID: joshua.41
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int maxBeads(string necklace, int n);

int main()
{
    ifstream inf ("beads.in");
    ofstream outf ("beads.out");
    
    int n; inf >> n;
    string necklace; inf >> necklace;
    
    outf << maxBeads(necklace, n) << '\n';
    return 0;
}

int maxBeads(string necklace, int n)
{
    char color;

    int max = 0;
    
    int r = 0;
    int l = 0;
    int rLength = 0;
    int lLength = 0;
    
    //find first colored bead
    while(necklace[r] == 'w')
    {
        r++;
        if (r == n) return n; //only white beads
    }
    
    do
    {
        color = necklace[r];
        l = r - 1;
        
        //count right until different color bead appears
        while(necklace[r%n] == color || necklace[r%n] == 'w')
        {
            rLength++;
            r++;
            if (rLength == n) return n; //only one sequence in the necklace
        }
        
        //find maximum removable beads on the left
        while(necklace[(l%n+n)%n] != color)
        {
            lLength++;
            l--;
        }
        
        if(rLength + lLength > max)
            max = rLength + lLength;
            
        rLength = lLength = 0;
    }
    while (r < n);
    
    if(max > n)
        return n;
    return max;
}
/*int maxBeads(string necklace, int n)
{
    int idx = 0;
    char color;
    int length = 0;
    int prevLength = 0;
    int max = 0;

    //find next color bead
    while(necklace[idx] == 'w')
    {
        idx++;
        if (idx == n) return n; //only white beads
    }
        
    int firstbead = idx;
    
    do
    {
        color = necklace[idx];
        
        //count until different color bead appears
        while(necklace[idx%n] == color || necklace[idx%n] == 'w')
        {
            length++;
            idx++;
            if (length == n) return n; //only one sequence in the necklace
        }
        
        if(length + prevLength > max)
            max = length + prevLength;
            
        prevLength = length;
        length = 0;
    }
    while (idx <= firstbead + n);
    
    return max;
}*/
