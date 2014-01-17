#include<string>
#include<map>

using namespace std;

int lengthOfLongestSubstring(string s) {

        if(s.size() == 0) return 0;

        int max = 1, start = 0, len = 1;

        map<char,int> pos;

        pos.insert(pair<char,int>(s[0],0));

        for(int i = 1; i < s.size(); i++)
        {
            if(pos.find(s[i]) == pos.end())
            {
                pos.insert(pair<char,int>(s[i],i));
                len++;
            }else{
                if(pos[s[i]] < start)
                {
                    len++;
                    pos[s[i]] = i;
                }else{
                    len -= pos[s[i]] - start;
                    start = pos[s[i]] + 1;
                    pos[s[i]] = i;
                }
            }

            max = max > len ? max : len;
        }//for

        return max;
    }
