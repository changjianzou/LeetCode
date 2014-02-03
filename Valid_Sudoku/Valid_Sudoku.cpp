#include<vector>

using namespace std;

bool isValidSudoku(vector<vector<char> > &board) {

        vector<vector<bool>> row(9, vector<bool> (9, false));
        vector<vector<bool>> col(9, vector<bool> (9, false));
        vector<vector<bool>> block(9, vector<bool> (9, false));

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                int c = board[i][j] - '1';

                if(board[i][j] != '.')
                {
                    if(row[i][c] || col[j][c] || block[i / 3 * 3 + j / 3][c]) return false;
                    row[i][c] = col[j][c] = block[i / 3 * 3 + j / 3][c] = true;
                }

            }
        }

        return true;
    }
