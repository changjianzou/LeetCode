#include<string>
#include<vector>

using namespace std;

bool isValid(string temp)
    {
        if(temp[0] == '0') return temp.size() == 1;

        int num = 0;

        for(int i = 0; i < temp.size(); i++)
        {
            num *= 10;

            num += temp[i] - '0';
        }

        return num >= 0 && num <= 255;
    }

    void restore(int section, vector<string>& ret, vector<string> &prefix, int len, string s)
    {
        if(section == 4)
        {
            if(len < s.size()) return;

            string temp;
            for(int i = 0; i < 3; i++)
            {
                temp.append(prefix[i]); temp.append(".");
            }
            temp.append(prefix[3]);
            ret.push_back(temp);
            return;
        }

        for(int i = 0; i < 3 && len + i + 1 <= s.size(); i++)
        {
            string temp = s.substr(len,i+1);

            if(!isValid(temp)) continue;

            prefix.push_back(temp);

            restore(section + 1, ret, prefix, len + i + 1, s);

            prefix.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {

        vector<string> ret;
        vector<string> prefix;
        restore(0, ret, prefix, 0, s);
        return ret;

    }
