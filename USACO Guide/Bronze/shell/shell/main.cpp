#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf ("shell.in");
    ofstream outf ("shell.out");
    
    int n; inf >> n;
    
    int pos[3] = {1, 2, 3};
    int correct[3]{};
    
    for (int i = 0; i < n; i++)
    {
        int s1, s2, guess;
        inf >> s1;
        inf >> s2;
        inf >> guess;
        
        for (int i = 0; i < 3; i++)
        {
            if (pos[i] == s1)
                pos[i] = s2;
            else if (pos[i] == s2)
                pos[i] = s1;
            
            if(pos[i] == guess)
                correct[i]++;
        }
    }
    
    outf << max(max(correct[0], correct[1]), correct[2]) << '\n';
    
    
    return 0;
}
