#include<vector>
#include<string>

using namespace std;
//using recursive
    void preComp(vector<vector<bool>> &isPal, string s)
    {
        for(int len = 2; len <= s.size(); len++)
        {
            for(int i = 0; i <= s.size() - len; i++)
            {
                if( s[i] != s[i + len - 1] )
                    isPal[i][i+len-1] = false;
                else
                    isPal[i][i+len-1] = len > 2 ? isPal[i+1][i+len-2] : true;
            }
        }
    }

    void partition(string s, int start, vector<vector<string>> &ret, vector<string> &sol, vector<vector<bool>> &isPal)
    {
        if(start >= s.size())
        {
            ret.push_back(sol);

            return;
        }

        for(int i = 1; i <= s.size() - start; i++)
        {
            if(isPal[start][start + i - 1] == false) continue;

            sol.push_back(s.substr(start,i));

            partition(s, start + i, ret, sol, isPal);

            sol.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ret;

        vector<vector<bool>> isPal(s.size(), vector<bool>(s.size(), true));

        preComp(isPal, s);

        vector<string> sol;

        partition(s, 0, ret, sol, isPal);

        return ret;
    }
