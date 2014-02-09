#include<vector>

using namespace std;

int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1;

        int max = 0, temp = 0;

        while(i < j)
        {
            temp = (j - i)*min(height[i], height[j]);

            max = max > temp ? max : temp;

            if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }
        }

        return max;
    }
