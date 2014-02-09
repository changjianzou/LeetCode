#include<vector>
#include<string>

using namespace std;

void generate(vector<string> &ret, string s, int l, int r, int n)
    {
        if(r == n)
        {
            ret.push_back(s); return;
        }

        if(l < n) generate(ret, s + "(", l + 1, r, n);

        if(l > r) generate(ret, s + ")", l, r + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s;
        generate(ret, s, 0, 0, n);
        return ret;
    }
