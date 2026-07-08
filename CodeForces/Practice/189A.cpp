#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, c; cin >> n >> a >> b >> c;

    vector<int> pieces(n+1, -1); 
    pieces[0] = 0;

    for (int length = 1; length <= n; length++)
    {
        int x = length-a >= 0 && pieces[length-a] != -1 ? pieces[length-a]+1 : -1;
        int y = length-b >= 0 && pieces[length-b] != -1 ? pieces[length-b]+1 : -1;
        int z = length-c >= 0 && pieces[length-c] != -1 ? pieces[length-c]+1 : -1;

        pieces[length] = max(max(x, y), z);
    }
    cout << pieces[n] << '\n';
}