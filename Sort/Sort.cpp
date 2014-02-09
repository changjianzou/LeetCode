 void swap(int A[], int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    void sortColors(int A[], int n) {

        int r = 0, w = 0, b = n - 1;

        while(w <= b){
            if(A[w] == 0){
                swap(A,r,w);r++;w++;
            }else if(A[w] == 2){
                swap(A,w,b);b--;
            }else{
                w++;
            }
        }

    }
