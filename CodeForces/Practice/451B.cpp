#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];
    vector<bool> decreased(n+1); for (int i = 2; i <= n; i++) decreased[i] = a[i] < a[i-1];

    bool valid = true;

    int reversals = 0;
    int start = -1;
    int end = -1;
    for (int i = 3; i <= n; i++)
    {
        if (decreased[i] != decreased[i-1]) reversals++;
    }

    if (reversals > 2)
        valid = false;
    else
    {
        for (int i = 3; i <= n; i++)
        {
            if (decreased[i] == true && decreased[i-1] == false)
                start = i-1;
            else if (decreased[i] == false && decreased[i-1] == true)
                end = i-1;
        }

        if (start == -1 && end == -1)
        {
            if (decreased[2])
            {
                start = 1;
                end = n;
            }
            else 
                start = end = 1;
        }
        else if (start == -1) 
        {
            if (a[1] < a[end+1])
                start = 1;
            else
                valid = false;
        }
        else if (end == -1) 
        {
            if (a[start-1] < a[n])
                end = n; 
            else 
                valid = false;
        }
        else if (start > end)
        {
            valid = false;
        }
        else 
        {
            valid = a[start] < a[end+1] && a[start-1] < a[end];
        }
    } 


    if (valid)
    {
        cout << "yes" << '\n';
        cout << start << ' ' << end << '\n';
    }
    else
    {
        cout << "no" << '\n';
    }
}