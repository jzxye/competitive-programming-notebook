#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf ("speeding.in");
    ofstream outf ("speeding.out");
    
    int n, m; inf >> n >> m;
    
    int limit[100];
    int speed[100];
    
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        int length, speedlimit; inf >> length >> speedlimit;
        for (int j = 0; j < length; j++)
        {
            limit[idx] = speedlimit;
            idx++;
        }
    }
    
    idx = 0;
    for (int i = 0; i < m; i++)
    {
        int length, cowSpeed; inf >> length >> cowSpeed;
        for (int j = 0; j < length; j++)
        {
            speed[idx] = cowSpeed;
            idx++;
        }
    }
    
    int maxExcess = 0;
    for (int i = 0; i < 100; i++)
    {
        if (speed[i] - limit[i] > maxExcess)
            maxExcess = speed[i] - limit[i];
    }
    
    outf << maxExcess << '\n';
    return 0;
}
