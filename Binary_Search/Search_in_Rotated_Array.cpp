//using binary search
    int search(int A[], int n, int target) {

        int low = 0, high = n - 1, mid = 0;

        while( low <= high )
        {
            mid = (low + high) / 2;

            if(A[mid] == target) return mid;

            if(A[mid] >= A[low]){

                if(A[mid] < target || target < A[low]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }

            }else{

                if(A[mid] > target || target >= A[low]){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }

            }
        }

        return -1;
    }
