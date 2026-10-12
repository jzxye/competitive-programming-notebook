#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, d; cin >> n >> m >> s >> d; 
    //new bottles, students, slots, capacity
    vector<pair<int,int>> c(s); //num bottles, index
    for (int i = 0; i < s; i++){
        int ci; cin >> ci;
        c[i] = {ci, i};
    }
    sort(c.begin(), c.end());

    vector<int> refill(s);
    
    int i = 0;
    while (n > 0){
        int amt = min(n, d-c[i].first);
        refill[c[i].second] = amt;
        n -= amt;
        i++;
    }

    int remaining = 0;
    for (; i < s; i++){
        remaining += c[i].first;
    }
    
    if (remaining >= m){
        for (int i = 0; i < s; i++)
            cout << refill[i] << ' ';
        cout << '\n';
    }else{
        cout << "impossible" << '\n';
    }



    
}