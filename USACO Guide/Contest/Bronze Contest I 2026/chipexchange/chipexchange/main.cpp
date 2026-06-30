#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main()
{
    int T; cin >> T;
    
    for (int i = 0; i < T; i++)
    {
        ll A, B, c_a, c_b, f_a;
        cin >> A >> B >> c_a >> c_b >> f_a;
        
        //first convert all possible B to A using the exchange rate
        //a random coin can be either A or B
        //case A:
        // +1 A
        //case B:
        // +1 B
        // if (B+1)% c_b == 0, +c_a A
        //we want the next coin to be B if adding that coin does not allow exchanging
        //either add A
        
        ll x = 0;
        A += B/c_b * c_a;
        B -= B/c_b * c_b;
        // B < c_b
        
        if (A >= f_a)
        {
            cout << 0 << '\n';
            continue;
        }
        
        x += c_b - B - 1;
        B += c_b - B - 1;



        if (c_a > c_b)
        {
            x += f_a - A;
        }
        else
        {
            x += (f_a - A - 1) / c_a * c_b;
            A += (f_a - A - 1) / c_a * c_a;
            

            
            //if (c_a  f_a - A )
           // x += max(f_a - A, );
            
            x += f_a - A;
        }
        
      /*  while (A < f_a)
        {
            if ((B+1) % c_b != 0)
                B++;
            else //adding one more B allows c_b -> c_a
            {
                if(c_b < c_a) A++;
                else
                {
                    A += c_a;
                    B = 0;
                }
            }
            
            
            x++;
        }*/
        
     /*   if (c_a >= c_b) //least optimal case is adding A's
        {
            cout << "c_a >= c_b: ";
            x = max((ll)0, f_a - A - B/c_b * c_a);
        }
        else
        {
          //  (A + c_a/c_b * (B+x) >= f_a);
           // x >= (f_a - A) * c_b/c_a -B;
            x = max((ll)0, (ll)ceil((f_a - A) * c_b/c_a) - B);
        }
       // ll x = max( max((ll)0, f_a - A), );*/
        cout << x << '\n';
        
    }
    return 0;
}
