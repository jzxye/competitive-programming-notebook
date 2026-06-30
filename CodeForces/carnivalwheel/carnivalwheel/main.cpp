#include <iostream>
using namespace std;

int main()
{
    int t; cin >> t;
    for (int i = 0; i < t; i++)
    {
        int l, a, b; cin >> l >> a >> b;
        
        bool visited[5000]{};
        int high = 0;
        int section = a;
        while (!visited[section%l])
        {
            visited[section%l] = true;
            high = max(high, section%l);
            section += b;
        }
        cout << high << '\n';
    }
    return 0;
}
