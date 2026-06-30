#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inf("promote.in");
    ofstream outf("promote.out");
    
    int bi, bf; inf >> bi >> bf;
    int si, sf; inf >> si >> sf;
    int gi, gf; inf >> gi >> gf;
    int pi, pf; inf >> pi >> pf;
    
    int bs, sg, gp; bs = sg = gp = 0;
    
    gp = pf - pi;
    sg = (gf - gi) + gp;
    bs = (sf - si) + sg;
    
    outf << bs << '\n' << sg << '\n' << gp << '\n';
    
    return 0;
}
