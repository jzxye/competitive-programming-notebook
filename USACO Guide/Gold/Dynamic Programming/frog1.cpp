#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];
    
    vector<int> M(N);
    for (int i = 1; i < N; i++){
        M[i] = M[i-1] + abs(h[i] - h[i-1]);

        if (i >= 2)
            M[i] = min(M[i], M[i-2] + abs(h[i] - h[i-2]));
    }
    cout << M[N-1] << '\n';
}