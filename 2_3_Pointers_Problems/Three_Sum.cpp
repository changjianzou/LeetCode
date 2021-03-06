#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {

        vector<vector<int> > ret;

        if(num.size() < 3) return ret;

        sort(num.begin(), num.end());

        vector<int> temp;


        int i = 0, j = 0, k = 0, sum = 0;

        for(i = 0; i < num.size(); i++)
        {
            if(i > 0 && num[i] == num[i-1]) continue;

            j = i + 1; k  = num.size()-1;

            while(j < k)
            {

                if(j > i + 1 && num[j] == num[j-1]) {j++; continue;}

                sum = num[i] + num[j] + num[k];

                if( sum == 0 )
                {
                    temp.push_back(num[i]);
                    temp.push_back(num[j]);
                    temp.push_back(num[k]);
                    ret.push_back(temp);
                    temp.clear();
                    j++; k--;
                }else if(sum > 0){
                    k--;
                }else{
                    j++;
                }

            }//while
        }//for

        return ret;
    }
