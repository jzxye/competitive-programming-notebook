 #include <iostream>
using namespace std;

int main()
{
    
    int n; cin >> n;
    int p[1000]; for (int i = 0; i < n; i++) cin >> p[i];
    
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        for (int j = i; j < n; j++)
        {
            total += p[j];

            if (total % (j-i+1) == 0)
            {
                int average = total/(j-i+1);
                for (int k = i; k <= j; k++)
                {
                    if (p[k] == average) {count++; break;}
                }
            }
        }
    }
    cout << count << '\n';
    return 0;
    
}
