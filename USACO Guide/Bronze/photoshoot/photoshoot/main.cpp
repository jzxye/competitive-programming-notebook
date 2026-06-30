#include <iostream>
#include <string>
using namespace std;

int main()
{
    //4 possible pairs: HG GH GG HH (last two are irrelevant)
    //observation: a swap changes the parity of all cows involved in the swap, so each possible swap should be executed once at most
    // longer swaps flip all the cows in all shorter swaps
    //short swaps cannot effect cows outside the range
    //a longer swap effectively permanently flips the first two cows, taking it out of range of shorter swaps
    //swap if first two cows are GH and last two are GH, otherwise, simply swap a shorter range
    
    //ex. GH__HG____GH__GHHG__GH
    //since we can ignore all HH, GG: consider the equivalent problem
    // we have a sequence of 1's and 0's (ex. 11001001101) how can we flip all of them to 1?
    // 11001 --> 01100 (HGHGGHGHHG --> GHHGHGGHGH)
    // an operation flips all of the leading digits and reverses them

    // observation: the only way to get to 111111111 is if the sequence is of the form 0000001111
    // observation: 0000 -> 1111, 1111 -> 0000
    
    // solution: 11001001101 -> 00001001101 -> 11111001101 -> 000000001101 -> 111111111101 -> 000000000001 -> 111111111111
    
    
    //sample input: GGGHGHHGHHHGHG <=> GHGHHGHGHG <=> 00111
    
    int n; cin >> n;
    
    bool sequence[100000];
    int relevantPairs = 0;

    for (int i = 0; i < n/2; i++)
    {
        char c1, c2; cin >> c1 >> c2;
        if (c1 == 'G' && c2 == 'H')
        {
            sequence[relevantPairs] = false;
            relevantPairs++;
        }
        else if (c1 == 'H' && c2 == 'G')
        {
            sequence[relevantPairs] = true;
            relevantPairs++;
        }
    }
    
    if (relevantPairs == 0)
    {
        cout << 0 << '\n';
        return 0;
    }
    
    int swaps = 0;
    bool prev = sequence[0];
    
    for (int i = 0; i < relevantPairs; i++)
    {
        if (sequence[i] != prev)
        {
            prev = !prev;
            swaps++;
        }
    }
    if(!sequence[relevantPairs-1]) swaps++;
    
    cout << swaps << '\n';
    
/*    int idx = -1;
    int gain = 0;
    for (int i = 0; i < n; i++)
    {
        if(order[i] == 'g')
        {
            if (i%2 == 0) g_odd++;
            else g_even++;
        }
        
        if(i % 2 == 1)
        {
            if (g_even - g_odd > gain)
            {
                gain = g_even - g_odd;
                idx = i;
            }
        }
    }
    
    int swaps = 0;
    string firstTwo = order.substr(0,2);
    for (int end = n-2; end >= 0; end-=2)
    {
        string lastTwo = order.substr(end, 2);
        
        if (lastTwo == "GH" && firstTwo != "HG")
        {
            firstTwo = "HG";
            swaps++;
        }
            
    }*/

    
   /* //observation: the position of holsteins is irrelevant
    //observation: a swap changes the parity of all cows involved in the swap, so each possible swap should be executed once at most
    // a longer swap will also effectively execute a shorter swap
    
    int reversals = 0;
    for (int i = n-1; i > 0; i-=2)
    {
        
    }
    
    cout << reversals << '\n';*/
    return 0;
}
