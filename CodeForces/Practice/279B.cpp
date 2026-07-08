#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,t; cin >> n >> t;
    vector<int> a(n); for (int &ai : a) cin >> ai;

    vector<int> aggtime(n); 
    aggtime[0] = a[0];
    for (int i = 1; i < n; i++)
        aggtime[i] = aggtime[i-1] + a[i];

    int skipped = 0;
    int books = 0;
    for (int i = 0; i < n; i++)
    {
        //bin search
        int j = i-1;
        for (int b = n; b >= 1; b /= 2)
            while (j+b < n && aggtime[j+b] - skipped <= t) 
                j+=b;

        books = max(books, j-i+1);
        skipped += a[i];
    }
    cout << books << '\n';
}