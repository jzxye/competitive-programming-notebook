#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin ("triangles.in");
    ofstream fout ("triangles.out");
    
    int n; fin >> n;
    int x[100]; int y[100];
    for (int i = 0; i < n; i++) fin >> x[i] >> y[i];
    
    int area = 0;
    for (int i = 0; i < n-2; i++)
    {
        for (int j = i+1; j < n-1; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if ((x[i] == x[j] && y[i] == y[k] ) || (x[i] == x[k] && y[i] == y[j])
                || (x[j] == x[k] && y[j] == y[i] ) || (x[j] == x[i] && y[j] == y[k])
                || (x[k] == x[i] && y[k] == y[j] ) || (x[k] == x[j] && y[k] == y[i]))
                    area = max(area, max(abs(x[i]-x[k]), abs(x[i] - x[j])) * max(abs(y[i]-y[k]), abs(y[i] - y[j])));
            }
        }
    }
    fout << area << '\n';
    return 0;
}
