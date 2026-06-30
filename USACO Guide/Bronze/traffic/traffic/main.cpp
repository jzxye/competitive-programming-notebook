#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
    ifstream inf ("traffic.in");
    ofstream outf ("traffic.out");
    
    int n; inf >> n;
    
    int lower{}, upper{};
    
    string ramp[100];
    int l[100];
    int u[100];
    
    int firstNone{};
    bool none = false;
    for (int i = 0; i < n; i++)
    {
        inf >> ramp[i] >> l[i] >> u[i];
        
        if (!none && ramp[i] == "none")
        {
            firstNone = i;
            lower = l[i];
            upper = u[i];
            none = true;
        }
    }
    
    for (int i = firstNone; i < n; i++)
    {
        if (ramp[i] == "on")
        {
            lower += l[i];
            upper += u[i];
        }
        else if (ramp[i] == "off")
        {
            lower -= u[i]; if(lower < 0) lower = 0;
            upper -= l[i];
        }
        else if (ramp[i] == "none")
        {
            if (l[i] > lower) lower = l[i];
            if (u[i] < upper) upper = u[i];
        }
    }
   int lf = lower;
    int uf = upper;
    
    for (int i = n-1; i >= 0; i--)
    {
        if (ramp[i] == "on")
        {
            lower -= u[i]; if(lower < 0) lower = 0;
            upper -= l[i];
        }
        else if (ramp[i] == "off")
        {
            lower += l[i];
            upper += u[i];
        }
        else if (ramp[i] == "none")
        {
            if (l[i] > lower) lower = l[i];
            if (u[i] < upper) upper = u[i];
        }
    }
    
    outf << lower << " " << upper << '\n';
    outf << lf << " " << uf << '\n';
    
   /* for (int i = 0; i < n; i++)
    {
        if (ramp[i] == "on")
        {
            lower += l[i];
            upper += u[i];
        }
        else if (ramp[i] == "off")
        {
            lower -= u[i];
            upper -= l[i];
        }
        else if (ramp[i] == "none")
        {
            if (l[i] > lower) lower = l[i];
            if (u[i] < upper) upper = u[i];
        }
    }
    outf << lower << " " << upper << '\n';*/

    return 0;
}
