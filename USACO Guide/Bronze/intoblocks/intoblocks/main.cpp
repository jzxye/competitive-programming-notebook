#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct range
{
    int first, last;
};

int main()
{
    int n, q; cin >> n >> q;
    vector<int> a(n+1); for (int i = 1; i <= n; i++) cin >> a[i];

    vector<range> m(200001);
    vector<int> count(200001);
    for (int i = 1; i <= n; i++)
    {
        if (m[i].first == 0) m[a[i]].first = m[a[i]].last = i;
        else m[a[i]].last = i;
        
        count[a[i]]++;
    }
    
    int difficulty = 0;
    
    int start, end; start = end = 1;
    while (end <= n)
    {
        int maxCount = 0;
        set<int> nums;
        for (int i = start; i <= end; i++)
        {
            if (nums.count(a[i]) == 0)
            {
                nums.insert(a[i]);
                end = max(end, m[a[i]].last);
                maxCount = max(maxCount, count[a[i]]);
            }
        }
        difficulty += end-start+1 - maxCount;
        start = end + 1;
        end = start;
    }
    
    cout << difficulty << '\n';
}
/*int main()
{
    int n, q; cin >> n >> q;
    vector<int> a(n); for (int &ai : a) cin >> ai;
    
    
    vector<int> order;
    set<int> s;
    
    map<int,range> m;
    vector<int> count(200001);
    vector<int> ogcount(200001);
    vector<vector<int>> indexes(200001);
    for (int i = 0; i < n; i++)
    {
        if (m.count(a[i]) == 0) m[a[i]].first = m[a[i]].last = i;
        else m[a[i]].last = i;
        
        count[a[i]]++; ogcount[a[i]]++;
        indexes[a[i]].push_back(i);
        
        if(s.count(a[i]) == 0) {
            s.insert(a[i]);
            order.push_back(a[i]);
        }
    }
    
    for (auto &p : m)
    {
        cout << "number: " << p.first << ", " << "range: " << p.second.first << ' ' << p.second.last
        << ", count: " << count[p.first] << '\n';
        
    }
    
    //a .... b...a......b
    // if two numbers overlap, swap the one with less elements

    //Time Complexity: O(NlogN)
    int difficulty = 0;
    for (int &num : order)
   // for (auto &p : m)
    {

        range &mi = m[num];
        for (int i = mi.first; i <= mi.last; i++)
        {
            if (a[i] != num)
            {
                if (count[a[i]] > count[num])
                {
                    cout << "changing " << num << " to " << a[i] << '\n';
                    difficulty += ogcount[num];
                    count[a[i]] += count[num];
                    count[num] = 0;
                    
                    m[a[i]].first = min(m[a[i]].first, m[num].first);
                    m[a[i]].last = max(m[a[i]].last, m[num].last);
                    m[num].last = -1;

                    for (int index : indexes[num])
                    {
                        a[index] = a[i];
                        indexes[a[i]].push_back(index);
                    }
                    
                    
                    
                    
                    
                    cout << "new array: ";
                    for (int x : a) cout << x << ' ';
                    cout << '\n';
                    
                    for (auto &mi : m)
                    {
                        cout << "number: " << mi.first << ", " << "range: " << mi.second.first << ' ' << mi.second.last
                        << ", count: " << count[mi.first] << '\n';
                    }
                    cout << "difficulty: " << difficulty << '\n';
                    cout << '\n';
                }
                else
                {
                    cout << "changing " << a[i] << " to " << num << '\n';

                    difficulty += ogcount[a[i]];
                    count[num] += count[a[i]];
                    count[a[i]] = 0;
                    
                    m[num].first = min(m[a[i]].first, m[num].first);
                    m[num].last = max(m[a[i]].last, m[num].last);
                    m[a[i]].last = -1;
                    
                    for (int index : indexes[a[i]])
                    {
                        a[index] = num;
                        indexes[num].push_back(index);
                    }

                    
                    
                    cout << "new array: ";
                    for (int x : a) cout << x << ' ';
                    cout << '\n';
                    
                    for (auto &mi : m)
                    {
                        cout << "number: " << mi.first << ", " << "range: " << mi.second.first << ' ' << mi.second.last
                        << ", count: " << count[mi.first] << '\n';
                    }
                    cout << "difficulty: " << difficulty << '\n';
                    cout << '\n';
                }
            }
        }
    }
    
    cout << difficulty << '\n';
    return 0;
}*/
