#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

const int NUM_BUCKETS = 10;

void findReading(set<int> &readings, vector<int> &b1, vector<int> &b2, int depth, int milk)
{
    if (depth == 5) //5th day
    {
        readings.insert(milk);
        return;
    }
    
    if (depth % 2 == 1) //barn 1 -> barn 2
    {
        for (int i = 0; i < 10; i++)
        {
            // ******NOTE: this can be more efficient with a queue, but i didn't want to change everything
            int cap = b1[0];
            b2.push_back(cap);
            b1.erase(b1.begin());
            findReading(readings, b1, b2, depth+1, milk - cap);
            b1.push_back(cap);
            b2.pop_back();
        }
        /*for (vector<int>::iterator i = b1.begin(); i < b1.end(); i++)
        {
            int cap = *i;
            b2.push_back(cap);
            i = b1.erase(i);
            findReading(readings, b1, b2, depth+1, milk - cap);
            b1.insert(i, cap);
        }*/
    }
    else //barn 2 -> barn 1
    {
        for (int i = 0; i < NUM_BUCKETS+1; i++)
        {
            int cap = b2[0];
            b1.push_back(cap);
            b2.erase(b2.begin());
            findReading(readings, b1, b2, depth+1, milk + cap);
            b2.push_back(cap);
            b1.pop_back();
        }
        /*
        for (vector<int>::iterator i = b2.begin(); i < b2.end(); i++)
        {
            int cap = *i;
            b1.push_back(cap);
            i = b2.erase(i);
            findReading(readings, b1, b2, depth+1, milk + cap);
            b2.insert(i, cap);
        }*/
    }
}

int main()
{
    ifstream fin ("backforth.in");
    ofstream fout ("backforth.out");
    
    vector<int> b1(NUM_BUCKETS);
    for (int i = 0; i < NUM_BUCKETS; i++)
        fin >> b1[i];
    
    vector<int> b2(NUM_BUCKETS);
    for (int i = 0; i < NUM_BUCKETS; i++)
        fin >> b2[i];
    
    set<int> readings;
    
    findReading(readings, b1, b2, 1, 0);
    fout << readings.size() << '\n';
    
    //for (int reading : readings)
      //  cout << reading << ' ';
    return 0;
}
