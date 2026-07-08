#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b; cin >> n >> m >> a >> b;

    //case 1: a <= b/m
    int p1 = n*a;

    //case 2: a > b/m
    //case 2.1: b >= n%m * a
    int p2 = n/m * b + n%m * a;
    //case 2.2: b < n%m * a
    int p3 = (n+m-1)/m * b; 

    cout << min(p1, min(p2, p3)) << '\n';
    
    
}