#include <iostream>
#include <fstream>
using namespace std;

struct interval
{
    int start;
    int end;
};
int main()
{
    ifstream fin ("lifeguards.in");
    ofstream fout ("lifeguards.out");
    
    int n; fin >> n;
    interval times[100];
    for (int i = 0; i < n; i++)
    {
        fin >> times[i].start >> times[i].end;
    }
    
   /* //sort
    for (int i = 0; i < n-1; i++)
    {
        int index = i;
        int min = times[i].start;
        for (int j = i+1; j < n; j++)
        {
            if (times[j].start < min)
            {
                min = times[j].start;
                index = j;
            }
        }
        int temp = times[i].start;
        times[i].start = min;
        times[index].start = temp;
        
        temp = times[i].end;
        times[i].end = min;
        times[index].end = temp;
    }*/
    

    
    int longest = 0;
    for (int i = 0; i < n; i++)
    {
        bool onduty[1000]{};
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            
            for (int t = times[j].start; t < times[j].end; t++)
                onduty[t] = true;
        }
        
        int timeOnDuty = 0; for(int t = 0; t < 1000; t++) if (onduty[t]) timeOnDuty++;
        longest = max(longest, timeOnDuty);
    }
    
    fout << longest << '\n';
    
    return 0;
}
