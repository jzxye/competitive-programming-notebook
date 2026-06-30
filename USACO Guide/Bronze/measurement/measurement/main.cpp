#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("measurement.in");
    ofstream fout ("measurement.out");
    
    int n; fin >> n;
    
    int milk [3][100]{};
    
    for (int i = 0; i < n; i++)
    {
        int day; string name; int change;
        fin >> day >> name >> change;
        
        int cow{};
        if (name == "Bessie") cow = 0;
        else if (name == "Elsie") cow = 1;
        else if (name == "Mildred") cow = 2;
        
        for (int j = day-1; j < 100; j++)
            milk[cow][j] += change;
    }
    
    int lead = 6; // 0: B, 1: E, 2: M, 3: B+E, 4: B+M, 5: E+M, 6: B+E+M
    int changes = 0;
    for (int day = 0; day < 100; day++)
    {
        int newLead = lead;
        if (milk[0][day] > milk[1][day] && milk[0][day] > milk[2][day])
            newLead = 0;
        else if (milk[1][day] > milk[0][day] && milk[1][day] > milk[2][day])
            newLead = 1;
        else if (milk[2][day] > milk[0][day] && milk[2][day] > milk[1][day])
            newLead = 2;
        else if (milk[0][day] == milk[1][day] && milk[0][day] > milk[2][day])
            newLead = 3;
        else if (milk[0][day] == milk[2][day] && milk[0][day] > milk[1][day])
            newLead = 4;
        else if (milk[1][day] == milk[2][day] && milk[1][day] > milk[0][day])
            newLead = 5;
        else if (milk[0][day] == milk[1][day] && milk[1][day] == milk[2][day])
            newLead = 6;
        
        if (newLead != lead)
        {
            changes++;
            lead = newLead;
        }
    }
    
    fout << changes << '\n';
    return 0;
}
