#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// T <= 100
// N, C, P <= 1000
const int NMAX = 1000;


string noun[NMAX];
string transitive[NMAX];
string intransitive[NMAX];
string conjunctions[NMAX];

//true if valid, false if not
bool countWords(int nc, int tc, int ic, int cc, int C, int P, int& count)
{
    if (nc < 2*tc + ic) return false;
    if (2*P < (tc+ic) || P + cc < tc + ic) return false;
    
    int tempCount = 0;
    bool even = false;
    while (ic--)
    {
        nc--;
        tempCount += 2;
        
        if (even && cc > 0)
        {
            cc--;
            tempCount++;
        }
        
        even = !even;
    }
    
    while(tc--)
    {
        nc-=2;
        tempCount += 3;
        
        if (even && cc > 0)
        {
            cc--;
            tempCount++;
        }
        
        even = !even;
        
        if(tc == 0)
        {
            while (C-- && nc--)
            {
                tempCount++;
            }
        }
    }

    count = tempCount;
    return true;
}

string generateParagraph(int nc, int tc, int ic, int cc, int C, int P)
{
    string paragraph;
    
    bool even = false;
    while (ic--)
    {
        if(even && cc > 0)
        {
            paragraph += " ";
            paragraph += conjunctions[--cc];
        }
        else
        {
            paragraph += '.';
            P--;
        }
        
        paragraph += " ";
        paragraph += noun[--nc];
        paragraph += ' ';
        paragraph += intransitive[ic];
        
        even = !even;
    }
    
    while(tc--)
    {
        if(even && cc > 0)
        {
            paragraph += " ";
            paragraph += conjunctions[--cc];
        }
        else
        {
            paragraph += '.';
            P--;
        }
        paragraph += " ";
        paragraph += noun[--nc];
        paragraph += " ";
        paragraph += transitive[tc];
        paragraph += " ";
        paragraph += noun[--nc];
        
        if(tc == 0)
        {
            while (nc > 0 && C > 0)
            {
                paragraph += ", " + noun[--nc];
                C--;
            }
        }
        
        even = !even;
    }
    paragraph += ".";
    
    //remove preceding ". "
    paragraph = paragraph.substr(2, paragraph.length()-2);
    
    return paragraph;
}

int main()
{
    int T; cin >> T;
    
    while (T--)
    {
        int N, C, P; cin >> N >> C >> P;
        

        int nc = 0;
        int tc = 0;
        int ic = 0;
        int cc = 0;
        
        for (int i = 0; i < N; i++)
        {
            string word, type;
            cin >> word >> type;
            
            if(type == "noun")
                noun[nc++] = word;
            else if (type == "transitive-verb")
                transitive[tc++] = word;
            else if (type == "intransitive-verb")
                intransitive[ic++] = word;
            else if (type == "conjunction")
                conjunctions[cc++] = word;
        }
        //sentence:
        //noun + intransitive
        //noun + transitive + noun(s) with commas separating
        //compound formed with a conjunction in between
        //end with a period
        
        //shove all the leftover commas and nouns into final intransitive sentence for simplicity
        //relevant parameters: # nouns, # transitive, # intransitive, # conjunction, # commas, # periods
        
        
        //first consider the problem without any commas
        // we have nouns, transitive, intransitive, conjunction, periods
        // Note that it is never better to sacrifice a transitive sentence for an intransitive one, unless there will be no intransitive sentences otherwise and you can't utilize your commas.
        // i.e. transitive gives 2 words per noun, intransitive gives 3 words per 2 nouns
        //
        //
        //
        // 1 noun, 1 intransitive, 1 period
        // 1 noun, 1 transitive, x nouns, x-1 commas, 1 period
        // 1 conjunction <=> 1 period
        
        // 5 nouns
        // 3 intransitive
        // 8 transitive
        // 3 conjunctions
        // 9 ,
        // 2 .
        
        // n i c n i
        // 3 1 8 2 9 1
        int maxWords = 0;
        string sentences;
        
        for (int nt = 0; nt <= tc; nt++)
        {
            for (int ni = 0; ni <= ic; ni++)
            {
                int count = 0;
                
                if (!countWords(nc, nt, ni, cc, C, P, count)) continue;
                

                if (count > maxWords)
                {
                    maxWords = count;
                    sentences = generateParagraph(nc, nt, ni, cc, C, P);
                }
                //generate sentence
            }
        }

        cout << maxWords << '\n';
        cout << sentences << '\n';

    }
    return 0;
}
