#include <iostream>
using namespace std;

int main()
{
    int num[7]; for (int i = 0; i < 7; i++) cin >> num[i];
    
    //sort
    for (int i = 0; i < 6; i++)
    {
        int minInd = i;
        int min = num[i];
        for (int j = i+1; j < 7; j++)
        {
            if (num[j] < min)
            {
                min = num[j];
                minInd = j;
            }
        }
        
        int temp = num[i];
        num[i] = num[minInd];
        num[minInd] = temp;
    }
    
    for (int i = 0; i < 4; i++)
        for (int j = i+1; j < 5; j++)
            for (int k = j+1; k < 6; k++)
                if(num[i] + num[j] + num[k] == num[6])
                    cout << num[i] << " " << num[j] << " " << num[k] << '\n';
    
    return 0;
}
