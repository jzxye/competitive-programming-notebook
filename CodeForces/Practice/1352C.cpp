#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--)
    {
        int n,k; cin >> n >> k;

        // ex. n=2, k=5  1,3,5,7,9 answer: 9 = 5
        // ex. n=3, k=7 1,2,4,5,7,8,10,11 answer: 10 = 3(k-1)/2 + k%3 == 0 ? 3 : k%3

        int answer = (k-1)/(n-1)*n;
        if (k%(n-1) == 0) answer += n-1;
        else answer += k%(n-1);

        cout << answer << '\n';
    }
}