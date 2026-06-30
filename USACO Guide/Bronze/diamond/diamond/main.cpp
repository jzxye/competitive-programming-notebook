#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("diamond.in");
    ofstream fout ("diamond.out");
    
    int n, k; fin >> n >> k;
    
    int diamonds[1000]; for (int i = 0; i < n; i++) fin >> diamonds[i];
    
    //sort
    for (int i = 0; i < n-1; i++)
    {
        int min = diamonds[i];
        int index = i;
        for (int j = i+1; j < n; j++)
        {
            if(diamonds[j] < min)
            {
                min = diamonds[j];
                index = j;
            }
        }
        int temp = diamonds[i];
        diamonds[i] = diamonds[index];
        diamonds[index] = temp;
    }
    
    int lower = 0, upper = 0;
    int most = 0;
    
    while (upper < n)
    {
        while (upper < n && diamonds[upper]-diamonds[lower] <= k) upper++;
        most = max(most, upper-lower);
        lower++;
    }
    
    fout << most << '\n';
    
    
    return 0;
}
