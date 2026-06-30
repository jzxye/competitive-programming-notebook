#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

struct rect
{
    int x,y;
    char c;
    
    void print()
    {
        for (int c = 0; c < y; c++)
        {
            for (int r = 0; r < x; r++)
                cout << this->c;
            cout << '\n';
        }
    }
};
//reimplementation
int main()
{
    rect logos[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> logos[i].x >> logos[i].y;
        logos[i].c = 'A' + i;
    }
    
    for (int i = 0; i < 3; i++)
        if (logos[i].y > logos[i].x)
            swap(logos[i].y, logos[i].x);
    
    if (logos[0].x > logos[1].x) swap(logos[0], logos[1]);
    if (logos[1].x > logos[2].x) swap(logos[1], logos[2]);
        
    int n = logos[2].x;
    
    //case 1: all same length {n, a} {n, b} {n, n-(a+b)}
    if (logos[0].x == logos[1].x && logos[0].x == n && logos[0].y + logos[1].y + logos[2].y == n)
    {
        cout << n << '\n';
        logos[0].print();
        logos[1].print();
        logos[2].print();
    }
    //case 2: {p, n-m} {n-p, n-m} {n, m}
    else
    {
        if (logos[0].x == n-logos[2].y) swap(logos[0].x, logos[0].y);
        if (logos[1].x == n-logos[2].y) swap(logos[1].x, logos[1].y);
        
        if (logos[0].x + logos[1].x == n && logos[0].y == n-logos[2].y && logos[1].y == n-logos[2].y)
        {
            cout << n << '\n';
            for (int c = 0; c < logos[0].y; c++)
            {
                for (int r = 0; r < logos[0].x; r++)
                    cout << logos[0].c;
                for (int r = 0; r < logos[1].x; r++)
                    cout << logos[1].c;
                cout << '\n';
            }
            logos[2].print();
        }
        else
        {
            cout << -1 << '\n';
        }

    }
    return 0;
}
    
/*int main()
{
    vector<tuple<int,int,char>> rect(3);
    for (int i = 0; i < 3; i++)
    {
        int x, y; cin >> x >> y;
        rect[i] = {max(x, y), min(x, y), 'A'+i};
    }
    
    sort(rect.begin(), rect.end());

    
    
    //square side length must be equal to the maximum length
    int n = get<0>(rect[2]);
    
    //case 1: all same length, widths add up to length
    if (get<0>(rect[0]) == get<0>(rect[1]) && get<0>(rect[1]) == get<0>(rect[2])
        && get<1>(rect[0]) + get<1>(rect[1]) + get<1>(rect[2]) == n)
    {
        cout << n << '\n';
        
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < get<1>(rect[i]); j++)
            {
                for (int k = 0; k < n; k++)
                    cout << get<2>(rect[i]);
                cout << '\n';
            }
        }
    }
    //case 2: AAAA
    //        AAAA
   //         BBBC
  //          BBBC
     
    else if(get<0>(rect[0]) == get<0>(rect[1]) && get<0>(rect[0]) == n-get<1>(rect[2])
            && get<1>(rect[0]) + get<1>(rect[1]) == n)
    {
        cout << n << '\n';
        for (int i = 0; i < get<0>(rect[0]); i++)
        {
            for (int j = 0; j < get<1>(rect[0]); j++)
                cout << get<2>(rect[0]);
            for (int j = 0; j < get<1>(rect[1]); j++)
                cout << get<2>(rect[1]);
            cout << '\n';
        }
        for (int j = 0; j < get<1>(rect[2]); j++)
        {
            for (int k = 0; k < n; k++)
                cout << get<2>(rect[2]);
            cout << '\n';
        }
    }
    else if(get<0>(rect[0]) == get<1>(rect[1]) && get<0>(rect[0]) == n-get<1>(rect[2])
            && get<1>(rect[0]) + get<0>(rect[1]) == n)
    {
        cout << n << '\n';
        for (int i = 0; i < get<0>(rect[0]); i++)
        {
            for (int j = 0; j < get<1>(rect[0]); j++)
                cout << get<2>(rect[0]);
            for (int j = 0; j < get<0>(rect[1]); j++)
                cout << get<2>(rect[1]);
            cout << '\n';
        }
        for (int j = 0; j < get<1>(rect[2]); j++)
        {
            for (int k = 0; k < n; k++)
                cout << get<2>(rect[2]);
            cout << '\n';
        }
    }
    else if(get<1>(rect[0]) == get<0>(rect[1]) && get<1>(rect[0]) == n-get<1>(rect[2])
            && get<0>(rect[0]) + get<1>(rect[1]) == n)
    {
        cout << n << '\n';
        for (int i = 0; i < get<1>(rect[0]); i++)
        {
            for (int j = 0; j < get<0>(rect[0]); j++)
                cout << get<2>(rect[0]);
            for (int j = 0; j < get<1>(rect[1]); j++)
                cout << get<2>(rect[1]);
            cout << '\n';
        }
        for (int j = 0; j < get<1>(rect[2]); j++)
        {
            for (int k = 0; k < n; k++)
                cout << get<2>(rect[2]);
            cout << '\n';
        }
    }
    else if(get<1>(rect[0]) == get<1>(rect[1]) && get<1>(rect[0]) == n-get<1>(rect[2])
            && get<0>(rect[0]) + get<0>(rect[1]) == n)
    {
        cout << n << '\n';
        for (int i = 0; i < get<1>(rect[0]); i++)
        {
            for (int j = 0; j < get<0>(rect[0]); j++)
                cout << get<2>(rect[0]);
            for (int j = 0; j < get<0>(rect[1]); j++)
                cout << get<2>(rect[1]);
            cout << '\n';
        }
        for (int j = 0; j < get<1>(rect[2]); j++)
        {
            for (int k = 0; k < n; k++)
                cout << get<2>(rect[2]);
            cout << '\n';
        }
    }
    else
    {
        cout << -1 << '\n';
    }

    
    return 0;
}*/
