/*
ID: joshua.41
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outf ("friday.out");
    ifstream inf ("friday.in");
    
    const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayOf13th[7] = {0, 0, 0, 0, 0, 0, 0};
    int dayOfWeek = 0; // Sat=0, Sun=1, M=2, T=3, W=4, R=5, F=6
                       //Jan 13th, 2000 -> start on sat
    
    int n; inf >> n;
    
    for (int i = 0; i < n; i++) //year
    {
        for (int j: daysInMonth) //month
        {
            int year = 1900 + i;
            if (  (j==28) && (year%4 == 0 && (year%100 != 0 || year%400 == 0))  )
                j++;
            
            dayOf13th[dayOfWeek]++;
            dayOfWeek = (dayOfWeek + j)%7;
            
            /*for (int k = 1; k <= j; k++) //day
            {
                if(k == 13)
                    dayOf13th[dayOfWeek]++;
                dayOfWeek = (dayOfWeek + 1)%7;
            }*/
        }
    }

    outf << dayOf13th[0];
    for (int i = 1; i < 7; i++)
        outf << " " << dayOf13th[i];
    outf << '\n';
    
    return 0;
}
