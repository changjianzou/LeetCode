 int removeDuplicates(int A[], int n) {

        if(n == 0) return 0;

        int len = 1, cnt = 1;

        for(int i = 1; i < n; i++)
        {
            if( A[i] != A[i-1] )
            {
                A[len] = A[i];
                len++;
                cnt = 1;
            }else{
                if(cnt == 1){
                    A[len] = A[i];
                    len++;
                }
                cnt++;
            }
        }

        return len;
    }
