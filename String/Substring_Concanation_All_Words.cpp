#include<vector>
#include<string>

using namespace std;

vector<int> findSubstring(string S, vector<string> &L) {

        vector<int> ret;

        int m = S.size(), n = L.size(), len = n == 0 ? 0 : L[0].size();

        if(m < n*len || n == 0 || len == 0) return ret;

        map<string,int> stat;
        map<string,int> cnt;

        int i = 0, j = 0;
        for(i = 0; i < n; i++)
        {
            stat[L[i]]++;
        }

        string temp;
        for(i = 0; i <= m - n*len; i++)
        {
            cnt.clear();
            for(j = 0; j < n; j++)
            {
                temp = S.substr(i + len*j, len);

                if(stat.find(temp) == stat.end()) break;

                cnt[temp]++;

                if(cnt[temp] > stat[temp]) break;
            }

            if(j == n)  ret.push_back(i);
        }

        return ret;
    }
