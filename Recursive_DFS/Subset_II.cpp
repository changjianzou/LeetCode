#include<vector>

using namespace std;

void subset(vector<int> &sub, int start, vector<int> &S, vector<vector<int>> &ret)
    {
        if(start == S.size()){ret.push_back(sub); return;}

        int len = 1;

        for(int i = start + 1; i < S.size(); i++){
            if(S[i] != S[i-1]) break;
            len++;
        }

        for(int i = 0; i <= len; i++)
        {
            if(i) sub.push_back(S[start+i-1]);
            subset(sub,start + len, S, ret);
        }

        sub.resize(sub.size() - len);

    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {

        vector<int> sub;

        vector<vector<int>> ret;

        if(S.size() == 0) return ret;

        sort(S.begin(), S.end());

        subset(sub, 0, S, ret);

        return ret;

    }
