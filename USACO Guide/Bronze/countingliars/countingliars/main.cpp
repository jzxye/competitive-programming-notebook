#include <iostream>
using namespace std;

void sort (int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min = arr[i];
        int index = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = min;
        arr[index] = temp;
    }
}
int main()
{
    
    int n; cin >> n;
    
    int l[1000]; int nl = 0;
    int g[1000]; int ng = 0;
    for (int i = 0; i < n; i++)
    {
        char c; cin >> c;
        int point; cin >> point;
        if (c == 'L')
        {
            l[nl] = point;
            nl++;
        }
        else
        {
            g[ng] = point;
            ng++;
        }
    }
    sort(l, nl); sort(g, ng);
    
    int minLiars = nl+ng;
    for (int gi = ng-1; gi >= 0;gi--)
    {
        int li = 0;
        while (li < nl && g[gi] > l[li]) li++;
        int liars = li + ng-1-gi;
        minLiars = min(liars, minLiars);
    }
    
    cout << minLiars << '\n';
    
    return 0;
}
