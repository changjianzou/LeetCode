#include<string>
#include<algorithm>

using namespace std;

bool check(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }

    //using DFS
    bool isScramble(string s1, string s2) {

        //corner cases
        if(s1.size() != s2.size() ) return false;

        if(check(s1,s2) == false) return false;

        if(s1.size() <= 1) return true;

        string l1, r1, l2, r2;
        for(int i = 0; i < s1.size() - 1; i++)
        {
            //no swap
            l1 = s1.substr(0,i+1); r1 = s1.substr(i+1);
            l2 = s2.substr(0,i+1); r2 = s2.substr(i+1);
            if( isScramble(l1,l2) && isScramble(r1,r2) )
            {
                return true;
            }

            //swap
            l2 = s2.substr(s2.size() - i - 1); r2 = s2.substr(0,s2.size()-i-1);
            if( isScramble(l1,l2) && isScramble(r1, r2) )
            {
                return true;
            }
        }

        return false;
    }
