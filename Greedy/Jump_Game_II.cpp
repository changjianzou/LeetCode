 //greedy algorithm
    int jump(int A[], int n) {
        int cnt = 0;

        int stop = n - 1, i = 0;

        while(stop > 0)
        {
            for(i = 0; i < stop; i++)
            {
                if(i + A[i] >= stop)
                {
                    stop = i;
                    break;
                }
            }
            cnt++;
        }

        return cnt;
    }
