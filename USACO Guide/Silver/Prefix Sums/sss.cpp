#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ifstream fin("div7.in");
    ofstream fout("div7.out");

    int N; fin >> N;
    vector<int> id(N);
    for (int i = 0; i < N; i++)
        fin >> id[i];
    
    vector<int> ps(N+1);
    for (int i = 1; i <= N; i++)
        ps[i] = (ps[i-1] + id[i-1])%7;

    int first[7]{}; for (int i = 0; i < 7; i++) first[i] = -1; 
    int last[7]{}; for (int i = 0; i < 7; i++) last[i] = -1; 

    for (int i = 0; i <= N; i++)
    {
        if (first[ps[i]] == -1) 
            first[ps[i]] = i;
        last[ps[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < 7; i++)
        ans = max(ans, last[i]-first[i]);
    
    fout << ans << '\n';

}