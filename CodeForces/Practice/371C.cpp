#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string recipe; cin >> recipe;
    int nb, ns, nc; cin >> nb >> ns >> nc;
    int pb, ps, pc; cin >> pb >> ps >> pc;
    ll r; cin >> r;

    int b, s, c; b = s = c = 0;
    for (char i : recipe)
    {
        switch (i)
        {
            case 'B':
                b++;
                break;
            case 'S':
                s++;
                break;
            case 'C':
                c++;
                break;
        }
    }

    ll count = 0;

    while (nb >= b && ns >= s && nc >= c)
    {
        count++;
        nb -= b;
        ns -= s;
        nc -= c;
    }

    //use up ingredients

    int qb = max(0, b-nb);
    int qs = max(0, s-ns);
    int qc = max(0, c-nc);
    int cost = qb * pb + qs * ps + qc * pc;
    int p = b * pb + s * ps + c * pc;

    while (cost < p && cost <= r)
    {
        count++;
        r -= cost;
        nb += qb - b;
        ns += qs - s;
        nc += qc - c;
        
        qb = max(0, b-nb);
        qs = max(0, s-ns);
        qc = max(0, c-nc);
        cost = qb * pb + qs * ps + qc * pc;
    }

    //buy 
    count += r/p; 
    
    cout << count << '\n';
}