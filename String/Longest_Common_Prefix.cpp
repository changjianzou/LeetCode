#include<vector>
#include<string>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {

        string common;

        if(strs.size() == 0) return common;

        int len = 0;

        while(len < strs[0].size())
        {
            char c = strs[0][len];

            for(int i = 1;  i < strs.size(); i++)
            {
                if(len >= strs[i].size() || c != strs[i][len]) return common;
            }

            common.push_back(c);

            len++;
        }

        return common;
    }
