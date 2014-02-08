#include<vector>

using namespace  std;

    bool searchMatrix(vector<vector<int> > &matrix, int target) {

        int m = matrix.size(), n = matrix[0].size();

        //search a row
        int low = 0, high = m - 1, mid = 0;

        while(low <= high)
        {
            mid = (low + high) / 2;
            if(matrix[mid][0] > target){
                high = mid - 1;
            }else{
                if(mid == m - 1 || matrix[mid+1][0] > target) break;
                low = mid + 1;
            }
        }

        if(low > high) return false;

        int row = mid;

        //search a column
        low = 0; high = n - 1; mid = 0;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(matrix[row][mid] == target){
                return true;
            }else if(matrix[row][mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return false;
    }
