#include<vector>
#include<stack>

using namespace std;

int largestRectangleArea(vector<int> &height) {

        int max = 0;

        height.push_back(-1);

        stack<int> workingS;

        workingS.push(0);

        for(int i = 1; i < height.size(); i++)
        {
            if(height[i] < height[workingS.top()])
            {

                 int ind = workingS.top();

                 while(!workingS.empty() && height[workingS.top()] >= height[i])
                 {
                     int h = height[workingS.top()];
                     workingS.pop();
                     int width = workingS.empty() ? ind + 1 : ind - workingS.top();
                     max = max > h*width ? max : h*width;
                 }
            }

            workingS.push(i);

        }

        height.pop_back();

        return max;
    }
