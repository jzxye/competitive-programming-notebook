#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    vector<int> A(N); 
    for (int i = 0; i < N; i++) 
        cin >> A[i];
    
    vector<int> prefix(N); prefix[0] = A[0];
    vector<int> suffix(N); suffix[N-1] = A[N-1];

    for(int i = 1; i < N; i++)
        prefix[i] = gcd(prefix[i-1], A[i]);
    for (int i = N-2; i >= 0; i--)
        suffix[i] = gcd(suffix[i+1], A[i]);

    int ans = 1;
    for (int i = 1; i < N-1; i++)
        ans = max(ans, gcd(prefix[i-1],suffix[i+1]));
    ans = max(max(ans, prefix[N-2]), suffix[1]);

    cout << ans << '\n';
}