#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

vector<string> anagrams(vector<string> &strs) {

        map<string,int> mymap;

        vector<string> ret;

        for(int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];

            sort(s.begin(), s.end());

            if(mymap.find(s) == mymap.end())
            {
                mymap.insert(pair<string,int>(s,i));
            }
            else
            {
                if(mymap[s] >= 0)
                {
                    ret.push_back(strs[mymap[s]]);
                    mymap[s] = -1;
                }

                ret.push_back(strs[i]);
            }
        }

        return ret;
    }
