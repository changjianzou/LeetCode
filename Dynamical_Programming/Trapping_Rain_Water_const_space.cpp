 int trap(int A[], int n) {

        int mid = 0, max = 0, vol = 0;

        for(int i = 0; i < n; i++)
        {
            mid = A[i] > A[mid] ? i : mid;
        }

        //from the left to right
        for(int i = 0; i < mid; i++)
        {
            max = max > A[i] ? max : A[i];
            vol += max - A[i];
        }

        //from the right to left
        max = A[n-1];

        for(int i = n - 1; i > mid; i--)
        {
            max = max > A[i] ? max : A[i];
            vol += max - A[i];
        }

        return vol;
    }
