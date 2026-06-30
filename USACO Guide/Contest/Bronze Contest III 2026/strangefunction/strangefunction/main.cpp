#include <iostream>
#include <string>
using namespace std;
using ll = long long;

const int xMAX = 200000;
const ll divisor = 1000000007;
int main()
{
    //observation: the function is just subtracting by one in binary, taking an extra operation if the ones digit is 0
    //ex. 111 --(1 operation)--> 110 --(2 operations)--> 101 --> etc..
    int T; cin >> T;
    while (T--)
    {
        string x; cin >> x;
        ll count = 0;
        
        bool binary = true;
        for (char digit : x)
            binary &= (digit == '0' || digit == '1');
        
        if (!binary)
        {
            for (char &digit : x)
            {
                int dig = digit - '0';
                if (dig % 2 == 0)
                    digit = '0';
                else
                    digit = '1';
            }
            
            count++;
        }
        
        int i = static_cast<int>(x.length()-1);
        if(x[i] == '1')
            ++count;
        --i;
        
        int operations = 3;
        while (i >= 0)
        {
            if (x[i] == '1')
                count = (count + operations) % divisor;
            
            --i;
            operations = (operations * 2) % divisor;
            
        }
        cout << count << '\n';
    }
    return 0;
}
