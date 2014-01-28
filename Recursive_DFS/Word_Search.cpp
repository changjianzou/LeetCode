#include<vector>

using namespace std;

int offset[4][2] = {{0,-1}, {1,0}, {0,1}, {-1,0}};

    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &visited, int x, int y, int len, string word)
    {
        int m = board.size(), n = board[0].size();

        if(len == word.size()) return true;

        if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y] == true || board[x][y] != word[len]) return false;

        visited[x][y] = true;

        for(int i = 0; i < 4; i++)
        {
            if(dfs(board, visited, x + offset[i][0], y + offset[i][1], len + 1, word)) return true;
        }

        visited[x][y] = false;

        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {

        if( board.size() == 0 ) return false;

        int m = board.size(), n = board[0].size();

        if(n == 0) return false;

        vector<vector<bool> > visited(m, vector<bool>(n,false));

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if( dfs(board, visited, i, j, 0, word) ) return true;
            }
        }

        return false;
    }
