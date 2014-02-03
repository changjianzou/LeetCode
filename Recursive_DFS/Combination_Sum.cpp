#include<vector>

using namespace std;

void dfs(int len, vector<int>&sol, int target, vector<int> &nums, vector<vector<int>> &ret)
    {
        if(len == nums.size())
        {
            if(target == 0) ret.push_back(sol);
            return;
        }

        int i = 0;
        for(i = 0; target - nums[len]*i >= 0; i++)
        {
            if(i) sol.push_back(nums[len]);
            dfs(len+1, sol, target - nums[len]*i, nums, ret);
        }

        for(int j = 0; j < i - 1; j++) sol.pop_back();
    }

    //using dfs
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {

        vector<vector<int>> ret;

        if(candidates.size() == 0) return ret;

        sort(candidates.begin(), candidates.end());

        vector<int> sol;

        dfs(0, sol, target, candidates, ret);

        return ret;
    }
