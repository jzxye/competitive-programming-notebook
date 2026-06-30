/*
ID: joshua.41
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getNameInd(string name, const string names[], int np);

int main()
{
    ifstream inf ("gift1.in");
    ofstream outf ("gift1.out");
    
    int np; inf >> np;
    string names[10]; for (int i = 0; i < np; i++) inf >> names[i];
    int money[10]; for (int i = 0; i < np; i++) money[i] = 0;
    
    for (int i = 0; i < np; i++)
    {
        string name; inf >> name;
        int gift, ng; inf >> gift >> ng;
        
     //   if (ng > 0) money[getNameInd(name, names, np)] += (gift % ng - gift);
        
        for (int j = 0; j < ng; j++)
        {
            string recipient; inf >> recipient;
            money[getNameInd(recipient, names, np)] += gift/ng;
            money[getNameInd(name, names, np)] -= gift/ng;
        }
            
    }
    
    for (int i = 0; i < np; i++)
        outf << names[i] << " " << money[i] << '\n';
    
    return 0;
}

int getNameInd(string name, const string names[], int np)
{
    for (int i = 0; i < np; i++)
        if (name == names[i])
            return i;
    return -1;
}
