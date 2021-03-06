#include<vector>

using namespace std;

    vector<int> spiralOrder(vector<vector<int> > &matrix) {

        vector<int> ret;

        if(matrix.size() == 0 || matrix[0].size() == 0) return ret;

        int m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < m / 2 && i < n / 2; i++)
        {//ith layer

            //top
            for(int j = i; j < n - i; j++)
            {
                ret.push_back(matrix[i][j]);
            }

            //right
            for(int j = i + 1; j < m - i; j++)
            {
                ret.push_back(matrix[j][n - 1 - i]);
            }

            //bottom
            for(int j = n - 2 - i; j >= i; j--)
            {
                ret.push_back(matrix[m-1-i][j]);
            }

            //left
            for(int j = m - 2 - i; j >= i + 1; j--)
            {
                ret.push_back(matrix[j][i]);
            }

        }


        if( m >= n && n % 2 )
        {//remaining column
            for(int i = n / 2; i < m - n / 2; i++)
            {
                ret.push_back(matrix[i][n/2]);
            }

        }

        if( m < n && m % 2 )
        {//remaining row

            for(int i = m / 2; i < n - m / 2; i++)
            {
                ret.push_back(matrix[m/2][i]);
            }
        }

        return ret;
    }
