#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n+1); for (int i = 1; i <= n; i++) cin >> a[i]; 

    //p[n]: max days of doing something such that i did not compete on day n
    //q[n]: max days of doing something such that i did not go to the gym on day n
    vector<int> p(n+1); p[0] = 0; p[1] = a[1] == 2 || a[1] == 3;
    vector<int> q(n+1); q[0] = 0; q[1] = a[1] == 1 || a[1] == 3;

    //Let P = gym, Q = contest
    //0: ~P, ~Q
    //1: ~P, Q
    //2: P, ~Q
    //3: P, Q
    for (int i = 2; i <= n; i++)
    {
        switch(a[i])
        {
            case 0:
                p[i] = q[i] = max(p[i-1], q[i-1]);
                break;
            case 1:
                p[i] = max(p[i-1], q[i-1]);
                q[i] = max(max(1 + p[i-1], q[i-1]), p[i-1]);
                break;
            case 2:
                p[i] = max(max(1+q[i-1], p[i-1]), q[i-1]);
                q[i] = max(p[i-1], q[i-1]);
                break;
            case 3:
                p[i] = max(max(1+q[i-1], p[i-1]), q[i-1]);
                q[i] = max(max(1+p[i-1], q[i-1]), p[i-1]);
                break;
        }
    }

    cout << min(n-p[n], n-q[n]) << '\n';
}