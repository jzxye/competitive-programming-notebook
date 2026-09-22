#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ifstream fin ("bcount.in");
    ofstream fout ("bcount.out");

    int N, Q; fin >> N >> Q;
    vector<int> one(N+1);
    vector<int> two(N+1);
    vector<int> three(N+1); 
    for (int i = 1; i<= N; i++)
    {
        int id; fin >> id;
        switch(id)
        {
            case 1:
                one[i] = 1;
                break;
            case 2:
                two[i] = 1;
                break;
            case 3:
                three[i] = 1;
                break;
        }
    }
    vector<int> ps1(N+1); partial_sum(one.begin()+1, one.end(), ps1.begin()+1);
    vector<int> ps2(N+1); partial_sum(two.begin()+1, two.end(), ps2.begin()+1);
    vector<int> ps3(N+1); partial_sum(three.begin()+1, three.end(), ps3.begin()+1);

    while (Q--)
    {
        int a, b; fin >> a >> b;
        fout << ps1[b]-ps1[a-1] << ' ' << ps2[b]-ps2[a-1] << ' ' << ps3[b]-ps3[a-1] << '\n';
    }
}