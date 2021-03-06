#include<vector>

using namespace std;

//using bs for two times
    vector<int> searchRange(int A[], int n, int target) {

        vector<int> ret;

        int low = 0, high = n - 1, mid = 0;

        //search lower bound
        while( low <= high ){

            mid = (low + high) / 2;

            if(A[mid] >= target){
                high = mid - 1;
            }else{
                low  = mid + 1;
            }
        }

        if(A[high + 1] != target) ret.push_back(-1);
        else ret.push_back(high+1);

        low = 0; high = n - 1;

        //search upper bound
        while( low <= high ){

            mid = (low + high) / 2;

            if(A[mid] > target){
                high = mid - 1;
            }else{
                low  = mid + 1;
            }
        }

        if(A[low - 1] != target) ret.push_back(-1);
        else ret.push_back(low-1);

        return ret;
    }
