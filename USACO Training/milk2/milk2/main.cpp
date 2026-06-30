/*
USER: joshua.41
LANG: C++
TASK: milk2
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inf ("milk2.in");
    ofstream outf ("milk2.out");
    
    int n; inf >> n;
    int milk[2][5000];
    for (int i = 0; i < n; i++) inf >> milk[0][i] >> milk[1][i];
    
    //isMilking represents a timeline of milking, where isMilking[i] tells you whether or not milking occurs in time interval [i, i+1)
    bool isMilking[1000000]; for (int i = 0; i < 1000000; i++) isMilking[i] = false;
    
    int startTime = milk[0][0];
    int endTime = milk[1][0];
    
    for (int i = 0; i < n; i++)
    {
        for(int j = milk[0][i]; j < milk[1][i]; j++)
            isMilking[j] = true;
        
        if (milk[0][i] < startTime)
            startTime = milk[0][i];
        if (milk[1][i] > endTime)
            endTime = milk[1][i];
    }
    
    int maxMilkInterval = 0;
    int noMilkInterval = 0;
    
    int interval = 0;
    for (int time = startTime; time < endTime; time++)
    {
        if(isMilking[time])
            interval++;
        else
            interval = 0;
        
        if (interval > maxMilkInterval)
            maxMilkInterval = interval;
    }
    
    interval = 0;
    for (int time = startTime; time < endTime; time++)
    {
        if(!isMilking[time])
            interval++;
        else
            interval = 0;
        
        if (interval > noMilkInterval)
            noMilkInterval = interval;
    }
    
    outf << maxMilkInterval << " " << noMilkInterval << '\n';
    
}
