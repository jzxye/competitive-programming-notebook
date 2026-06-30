#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;
    string order; cin >> order;
    int e[100001]; for (int i = 1; i <= n; i++) cin >> e[i];
    
    //leader must be the first cow of its breed, or must come before first cow of the other breed

    char first = order[0];
    int secondIndex = 1;
    while (order[secondIndex-1] == first) secondIndex++;
    
    int lastIndex1 = n; while(order[lastIndex1-1] != first) lastIndex1--;
    int lastIndex2 = n; while(order[lastIndex2-1] == first) lastIndex2--;
        
    int validPairs = 0;
    //case 1: first cow of each breed is the leader
    if (e[1] >= lastIndex1 && e[secondIndex] >= lastIndex2) validPairs++;
        
    //case 2: first cow of second breed is the leader, any cow preceding this cow of the other breed is the leader
    for (int i = 1; i < secondIndex; i++)
    {
        if (i == 1 && validPairs == 1) continue; //prevent overcounting
        if (order[i-1] == first && e[i] >= secondIndex)
        {
            validPairs++;
        }
    }
    
    cout << validPairs << '\n';
    return 0;
}
