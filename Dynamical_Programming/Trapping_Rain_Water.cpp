 //two pass algorithm
    int trap(int A[], int n) {

        if(n <= 1) return 0;

        int* highest = new int[n];

        highest[0] = A[0];

        for(int i = 1; i < n; i++)
        {
            highest[i] = A[i] > highest[i-1] ? A[i] : highest[i-1];
        }

        int max = A[n-1], vol = 0;

        //scan from right to left
        for(int i = n - 2; i >= 0; i--)
        {
            max = max > A[i] ? max : A[i];
            vol += max > highest[i] ? highest[i] - A[i] : max - A[i];
        }

        return vol;
    }
