#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ifstream fin("hps.in");
    ofstream fout("hps.out");

    int N; fin >> N;
    vector<char> fj(N+1);
    for (int i = 1; i <= N; i++)
        fin >> fj[i];
    
    vector<int> H(N+1);
    vector<int> P(N+1);
    vector<int> S(N+1);
    for (int i = 1; i <= N; i++)
    {
        H[i] = H[i-1]; 
        P[i] = P[i-1];
        S[i] = S[i-1];

        if (fj[i] == 'H')
            P[i]++;
        else if (fj[i] == 'P')
            S[i]++;
        else if (fj[i] == 'S')
            H[i]++;
    }

    //naive solution
    int max_wins = 0;
    for (int i = 0; i <= N; i++)
    {
        max_wins = max(max_wins, 
            max(H[i] + P[N] - P[i],
            max(H[i] + S[N] - S[i],
            max(P[i] + H[N] - H[i],
            max(P[i] + S[N] - S[i],
            max(S[i] + H[N] - H[i],
                S[i] + P[N] - P[i]
            )
            )
            )
            )
            )
        );
    }

    fout << max_wins << '\n';
}