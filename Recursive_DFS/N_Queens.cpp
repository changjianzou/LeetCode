#include<vector>
#include<string>

using namespace std;

void dfs(int row, vector<int> &col, vector<vector<string>> &ret)
    {
        //corner case
        if(row == col.size())
        {
            vector<string> sol; string temp;
            for(int i = 0; i < col.size(); i++)
            {
                string temp(col.size(), '.');
                temp[col[i]] = 'Q';
                sol.push_back(temp);
            }

            ret.push_back(sol);
            return;
        }

        int i = 0, r = 0;
        for(i = 0; i < col.size(); i++)
        {
            for(r = 0; r < row; r++)
            {
                if(col[r] == i || abs(col[r] - i)  == row - r ) break;
            }

            if(r == row)
            {
                col[row] = i;

                dfs(row+1, col, ret);
            }
        }
    }

    //using recursive
    vector<vector<string> > solveNQueens(int n) {

        vector<vector<string>> ret;

        if(n == 0) return ret;

        vector<int> col(n,0);

        dfs(0, col, ret);

        return ret;
    }
