#include <iostream>
using namespace std;

int main()
{
    int T; cin >> T;
    
    while (T--)
    {
        int N, A, B; cin >> N >> A >> B;
        
        int sky[1000][1000];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                char star; cin >> star;
                
                int count = 0;
                if (star == 'W') count = 0;
                else if (star == 'G') count = 1;
                else if (star == 'B') count = 2;
                
                sky[i][j] = count;
            }
        }
        
        bool stars[1000][1000]{};
        bool invalid = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (sky[i][j] == 0)
                {
                    //do nothing
                }
                else if (sky[i][j] == 1)
                {
                    if (i < B || j < A) stars[i][j] = true;
                    else if (!stars[i-B][j-A]) stars[i][j] = true;
                }
                else if (sky[i][j] == 2)
                {
                    
                    if (i < B || j < A) invalid = true;
                    else if (sky[i-B][j-A] == 0) invalid = true;
                    
                    stars[i][j] = true;
                    if (i >= B && j >= A) stars[i-B][j-A] = true;
                }
            }
        }
        
        if (invalid)
        {
            cout << -1 << '\n';
            continue;
        }
        
        int numStars = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (stars[i][j]) numStars++;
        
        cout << numStars << '\n';
    }

        /*
        int numStars = 0;
        bool star[1000][1000]{};
        for(int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                if (sky[i][j] == 2)
                {
                    star[i][j] = true;
                    star[((i-B)%N+N)%N][((j-A)%N+N)%N] = true;
                }
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (sky[i][j] == 1)
                {
                    if (!star[i][j] && !star[((i-B)%N+N)%N][((j-A)%N+N)%N])
                    {
                        star[i][j] = true;
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (sky[i][j] == 0 && star[i][j])
                    numStars = -1;
    
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << star[i][j];
            cout << '\n';
        }
        
        if (numStars == -1)
        {
            cout << -1 << '\n';
            continue;
        }
        
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (star[i][j]) numStars++;
        
        cout << numStars << '\n';
        
    }*/
    return 0;
}
