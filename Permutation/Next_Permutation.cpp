#include<vector>
#include<algorithm>

using namespace std;

void swap(int i, int j, vector<int>&num)
    {
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }

    void nextPermutation(vector<int> &num) {

        int i = 0, j = 0;

        for(i = num.size() - 2; i >= 0; i--)
        {
            if(num[i] < num[i+1]) break;
        }

        if(i >= 0)
        {
            for(j = num.size() - 1; j > i; j--)
            {
                if(num[j] > num[i]) break;
            }

            swap(i,j,num);
        }

        reverse(num.begin() + i + 1, num.end());

    }
