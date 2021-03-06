#include<vector>
#include<map>

using namespace std;

void permute(int len, int n, vector<int> &unique, map<int,int> &cnt, vector<vector<int>> &ret, vector<int> &sol)
    {
        if(len == n){
            ret.push_back(sol); return;
        }

        for(int i = 0; i < unique.size(); i++)
        {
            if(cnt[unique[i]] == 0) continue;

            cnt[unique[i]]--;

            sol.push_back(unique[i]);

            permute(len + 1, n, unique, cnt, ret, sol);

            cnt[unique[i]]++;

            sol.pop_back();
        }
    }

    //using recursive
    vector<vector<int> > permuteUnique(vector<int> &num) {

        vector<vector<int>> ret;

        vector<int> unique;

        map<int,int> cnt;

        for(int i = 0; i < num.size(); i++)
        {
            if(cnt.find(num[i]) == cnt.end()) unique.push_back(num[i]);

            cnt[num[i]]++;
        }

        vector<int> sol;

        permute(0, num.size(), unique, cnt, ret, sol);

        return ret;
    }
