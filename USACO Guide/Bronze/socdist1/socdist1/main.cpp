#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
     ifstream fin ("socdist1.in");
     ofstream fout ("socdist1.out");
    
    int n; fin >> n;
    bool occupied[100000];
    
    for (int i = 0; i < n; i++)
    {
        char o; fin >> o;
        occupied[i] = (o == '1' ? true : false);
    }
    
    
    int prev = 0;
    while (prev < n && !occupied[prev]) prev++;
    int left = prev; //number of 0s before first 1
    
    int end = n-1;
    while (end >= 0 && !occupied[end]) end--;
    int right = n - end - 1; //number of 0s after last 1

    //edge case 0000000
    if (prev == n)
    {
        fout << n-1 << '\n';
        return 0;
    }
        
        
    int curr = prev;
    
    int maxD[2]{};
    int minD = INT_MAX;
    
    //ends  00010000010000
    
    for (;;)
    {
        do curr++;
        while (curr < end && !occupied[curr]);
        
        int d = curr - prev;
        
        if (occupied[curr]) maxD[1] = max(maxD[1], d);
        if(maxD[0] < maxD[1]) swap(maxD[0], maxD[1]);
        

        if (occupied[curr]) minD = min(minD, d);
        
        if (curr >= end) break;

        
        prev = curr;
    }
    
    
    //5 cases:
    // cow splits two longest
    //cow goes on both ends
    //cow goes on one end and splits biggest
    //cow goes on one end and splits end
    //cow splits longest into thirds
    
    //if cow splits the minimum, it creates a new min
    
    //edge case 000000010000
    int case1 = 0;
    if (left > 0 && right > 0)
        case1 = min (min(left, right), minD);
    
    //
    int case2 = 0;
    if(maxD[0] >= 2 && maxD[1] >= 2)
        case2 = min (min(maxD[0]/2, maxD[1]/2), minD);
    
    int case3 = 0;
    if(maxD[0] >= 2 && max(left,right) >= 1)
        case3 = min (min(maxD[0]/2, max(left, right)), minD);
    
    int case4 = 0;
    if (max(left,right) >= 2)
        case4 = min (max(left,right)/2, minD);
    
    int case5 = 0;
    if (maxD[0] >= 3)
        case5 = min (maxD[0]/3, minD);
    
    int case6 = 0;
    if(maxD[1] == 0) case6 = min (left, right);
    
    //edge case 0000000000
    fout << max(max(max(max(max(max(case1,case2), case3),case4),case5),case6),1) << '\n';

    //revision: some cases not always possible
    // actually, we only have to check the cases where the cow placement is considered cheating (gives an advantage)
    // but easier to just check all
    // ex. case2 11111111100
  /*  int swaps = 2;
    if (2 * left >= maxD[1])
    {
        maxD[1] = left;
    }
    
    if (2 * maxD[0] >= 3 * maxD[1])
    {
        //split d_1 with two cows
        maxD[0] /= 3;
    }
    else
    {
        //split both with one cow
        maxD[0] /= 2;
        maxD[1] /= 2;
    }
    
    cout << min(minD, min(maxD[0], maxD[1])) << '\n';*/
    

    return 0;
}
