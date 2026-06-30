#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    unordered_map<string, int> count;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        if (count[s] == 0) 
            cout << "OK" << '\n';
        else
            cout << s << count[s] << '\n';
        count[s]++;
    }
}