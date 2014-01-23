//find kth element
    double findKth(int A[], int m, int B[], int n, int k){

        if(m <= 0) return B[k-1];
        if(n <= 0) return A[k-1];

        if(k > m/2 + n/2 + 1)
        {
            if(A[m/2] >= B[n/2])
            {
                return findKth(A, m, B+n/2+1, n - n / 2 - 1, k- n/2 - 1);
            }
            else
            {
                return findKth(A+m/2+1, m - m / 2 - 1, B, n, k - m/2 - 1);
            }
        }
        else
        {
            if(A[m/2] >= B[n/2])
            {
                return findKth(A,m/2,B,n,k);
            }
            else
            {
                return findKth(A,m,B,n/2,k);
            }
        }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {

        if( (m+n) % 2 == 0)
        {
            return (findKth(A,m,B,n,(m+n)/2) + findKth(A,m,B,n,(m+n)/2+1)) / 2;
        }
        else
        {
            return findKth(A,m,B,n,(m+n)/2+1);
        }

    }
