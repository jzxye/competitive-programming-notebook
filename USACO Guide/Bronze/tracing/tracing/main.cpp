#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

const int NMAX = 100;
const int TMAX = 250;

struct handshake
{
    int t, x, y;
    
    handshake()
    {}
    
    handshake(int t, int x, int y)
    : t{t}, x{x}, y{y}
    {}
    
    bool operator<(const handshake& other) const
    {
        return t < other.t;
    }
};

int main()
{
    ifstream fin("tracing.in");
    ofstream fout("tracing.out");
    // once a cow shakes K times, it cannot become contagious again
    int N, T; fin >> N >> T;
    
    //process data
    bool infected[NMAX]{};
    for (int i = 0; i < N; i++) {
        char c; fin >> c;
        infected[i] = c == '1';
    }
    
    handshake timeline[TMAX];
    int hoofshakes[NMAX]{};
    for (int i = 0; i < T; i++)
    {
        int t, x, y; fin >> t >> x >> y;
        timeline[i] = handshake(t, --x, --y);
        hoofshakes[x]++;
        hoofshakes[y]++;
    }
    sort(timeline, timeline+T);
    
    
    //solve
    int x, y, z;
    x = 0;
    y = INT_MAX;
    z = INT_MIN;

    int kmax = 0;
    for (int i = 0; i < N; i++) kmax = max(kmax, hoofshakes[i]);
    
    
    //test patient zero candidacy
    for (int c = 0; c < N; c++)
    {
        bool cValid = false;
        for (int k = 0; k <= kmax; k++)
        {
            int currhoofshakes[NMAX]{};
            bool currInfected[NMAX]{};
            currInfected[c] = true;
            //simulate
            for (int t = 0; t < T; t++)
            {
                handshake h = timeline[t];
                if (!currInfected[h.x] && !currInfected[h.y]) continue;
                
                if (currInfected[h.x]) currhoofshakes[h.x]++;
                if (currInfected[h.y]) currhoofshakes[h.y]++;
                
                if (currhoofshakes[h.x] <= k && currhoofshakes[h.y] <= k)
                    currInfected[h.x] = currInfected[h.y] = true;
            }
            
            //if it works
            bool valid = true;
            for (int i = 0; i < N; i++)
                valid &= currInfected[i] == infected[i];
            
            if(valid)
            {
                cValid = true;
                y = min(y, k);
                z = max(z, k);
                
                if (k == kmax)
                    z = INT_MAX;
            }
        }
        if (cValid) x++;
        
    }
    
    if (z == INT_MAX)
        fout << x << ' ' << y << ' ' << "Infinity" << '\n';
    else
        fout << x << ' ' << y << ' ' << z << '\n';
    
    return 0;
}


/*
struct handshake
{
    int t, x, y;
    
    handshake(){}

    handshake(int t, int x, int y)
     : t(t), x(x), y(y) {}

    bool operator<(const handshake &hs)
    {
        return t < hs.t;
    }
};




int main()
{
    ifstream fin ("tracing.in");
    ofstream fout ("tracing.out");
    
    int N, T; fin >> N >> T;
    
    bool infected[NMAX+1];
    for (int i = 1; i <= N; i++)
    {
        char c; fin >> c;
        infected[i] = (c == '1');
    }
    
    handshake timeline[TMAX];
    for (int i = 0; i < T; i++)
    {
        int t, x, y; fin >> t >> x >> y;
        timeline[i] = handshake(t, x, y);
    }
    sort(timeline, timeline+T);
    
    
    int x = 0; //# of patient zero possiblilities
    int y = INT_MAX; // smallest possible K
    int z = 0; // greatest possible K
    
    for (int pzero = 0; pzero < N; pzero++)
    {
        if (!infected[pzero]) continue;
        
        bool currInfected[NMAX+1]{};
        currInfected[pzero] = true;
        
        int infectedHoofshakes[NMAX+1]{};
        
        int kmin = 0;
        int kmax = INT_MAX;
        
        //first pass: determine k
        for (int t = 0; t < T; t++)
        {
            const handshake & hs = timeline[t];
            if(!currInfected[hs.x] && !currInfected[hs.y]) continue;
            
            //observation: k must be restricted if a handshake transmits covid to a cow that is not infected
            //observation: if for all cows # hoofshakes <= this k value, then the patient zero is valid
            //if a
            if(currInfected[hs.x])
            {
                if(infected[hs.y])
                {
                    currInfected[hs.y] = true;
                    infectedHoofshakes[hs.x]++;
                }
                else
                {
                    kmax = min(kmax, infectedHoofshakes[hs.x]);
                }
            }
            else if(currInfected[hs.y])
            {
                if(infected[hs.x])
                {
                    currInfected[hs.x] = true;
                    infectedHoofshakes[hs.y]++;
                }
                else
                {
                    kmax = min(kmax, infectedHoofshakes[hs.y]);
                }
            }
        }

        
        //reset
        for (int i = 1; i <= N; i++)
            currInfected[i] = false;
        currInfected[pzero] = true;
        
        for (int i = 1; i <= N; i++)
         infectedHoofshakes[i] = 0;
        
        //second pass: determine k validity
        bool valid = true;
        for (int t = 0; t < T; t++)
        {
            const handshake & hs = timeline[t];
            if(!currInfected[hs.x] && !currInfected[hs.y]) continue;
            
            if(currInfected[hs.x])
            {
                if (infectedHoofshakes[hs.x] < kmax)
                {
                    currInfected[hs.y] = true;
                    infectedHoofshakes[hs.x]++;
                }
            }
            else if(currInfected[hs.y])
            {
                if (infectedHoofshakes[hs.y] < kmax)
                {
                    currInfected[hs.x] = true;
                    infectedHoofshakes[hs.y]++;
                }
            }
        }
        for (int i = 1; i <= N; i++)
            if (currInfected[i] != infected[i]) valid = false;
        
        if (valid)
        {
            for (int i = 1; i <= N; i++)
                kmin = max(kmin, infectedHoofshakes[i]);
            x++;
            y = min(y, kmin);
            z = max(z, kmax);
        }
    }
    
    
    //print
    fout << x << ' ' << y << ' ';
    if (z == INT_MAX) fout << "Infinity";
    else fout << z;
    fout << '\n';
    
    return 0;
}

*/
