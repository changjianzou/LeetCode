#include<iostream>

using namespace std;

//get the kth and (k+1)th number
void findMedian(int A[], int m, int B[], int n, int& m1, int& m2, int k)
 {
     if(m <= 0) {m1 = k >= 1 ? B[k - 1] : 0; m2 = B[k]; return;}
     if(n <= 0) {m1 = k >= 1 ? A[k - 1] : 0; m2 = A[k]; return;}

     int i = (int)((double) (m*(k-1)) / (double)(m+n) ), j = k - 1 - i;
     if(i >= m){i = m - 1; j = k - m;}
     if(j >= n){j = n - 1; i = k - n;}

     if(A[i] >= B[j])
     {
         if( i >= 1 && B[j] < A[i-1] ){
             findMedian(A, i+1, B + j + 1, n - j - 1, m1, m2, k-j-1);
         }else{
             m1 = B[j]; m2 = j < n-1 && A[i] > B[j+1] ? B[j+1] : A[i];
         }
     }else{
         if( j >= 1 && A[i] < B[j-1]){
             findMedian(A + i + 1, m - i - 1,  B, j+1, m1, m2, k-i-1);
         }else{
             m1 = A[i]; m2 = i < m-1 && B[j] > A[i+1] ? A[i+1] : B[j];
         }
     }
 }

 double findMedianSortedArrays(int A[], int m, int B[], int n) {

     int m1 = 0, m2 = 0, k = (m+n)/2;

     findMedian(A, m, B, n, m1, m2, k);

     return (m+n) % 2 == 0 ? ((double)m1 + (double)m2) / 2 : (double)m2;
 }


    void test()
    {
    	int m = 2, n = 2;
    	int A[2] = {1,4};
    	int B[2] = {2,3};
    	cout<<findMedianSortedArrays(A,m,B,n)<<endl;
    }

    int main(){
    	test();
    }
