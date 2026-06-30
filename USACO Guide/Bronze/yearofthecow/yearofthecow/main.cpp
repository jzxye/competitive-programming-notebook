#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int mod (int q, int d)
{
    if (q < 0) return mod(q+d, d);
    return q%d;
}

int main()
{
    int n; cin >> n;
    
    map<string,int> years; years["Bessie"] = 0;
    string zodiacs[12]{"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse",
        "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    
    for (int i = 0; i < n; i++)
    {
        string currentCow, direction, zodiac, prevCow;
        string trash;
        
        cin >> currentCow >> trash >> trash >> direction >> zodiac >> trash >> trash >> prevCow;
                
        int dir{};
        if (direction == "previous") dir = -1;
        else if (direction == "next") dir = 1;
        
        int year = years[prevCow];
        
        // the idiom to get a positive modulo is (a%b+b)%b
        do year += dir;
        while(zodiacs[mod(year, 12)] != zodiac);
    
        years[currentCow] = year;
        
    }
    
    cout << abs(years["Bessie"] - years["Elsie"]) << '\n';
    
    return 0;
}
