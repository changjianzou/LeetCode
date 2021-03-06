#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//using recursive
    void combination(vector<int> &num, map<int,int> &cnt, vector<vector<int> > &ret, vector<int> &sol, int n, int target)
    {

        if(target <= 0 || n == num.size())
        {
            if(target == 0) ret.push_back(sol);

            return;
        }

        for(int i = 0; i <= cnt[num[n]]; i++)
        {
            if(i) sol.push_back(num[n]);

            combination(num, cnt, ret, sol, n + 1, target - i*num[n]);
        }

        for(int i = 0; i < cnt[num[n]]; i++) sol.pop_back();

    }

    vector<vector<int> > combinationSum2(vector<int> &num, int target) {

        sort(num.begin(), num.end());

        vector<int> unique;

        map<int,int> cnt;

        for(int i = 0; i < num.size(); i++)
        {
            if(cnt.find(num[i]) == cnt.end()) unique.push_back(num[i]);
            cnt[num[i]]++;
        }

        vector<int> sol;

        vector<vector<int>> ret;

        combination(unique, cnt, ret, sol, 0, target);

        return ret;
    }
