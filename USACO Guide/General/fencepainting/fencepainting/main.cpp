#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf ("paint.in");
    ofstream outf ("paint.out");
    
    int a, b, c, d; inf >> a >> b >> c >> d;
    
    //case 1: a < b < c < d (no overlap) return b-a + d-c
    //case 2: c < d < a < b
    //case 2: a < c < b < d (overlap) return
    //case 3: c < a < d < b (overlap)
    //case 4: a < c < d < b
    //case 5: c < a < b < d
    bool painted[100] = {};
    for (int i = a; i < b; i++)
        painted[i] = true;
    for (int i = c; i < d; i++)
        painted[i] = true;
    
    int length {0};
    for (int i = 0; i < 100; i++)
        if (painted[i]) length++;
    
    outf << length << '\n';
    
    
    return 0;
}
