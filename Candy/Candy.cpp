#include<vector>

using namespace std;

int candy(vector<int> &ratings) {

        if(ratings.size() == 0) return 0;

        int total = 1, cur = 1, max = 1, len = 0, i = 1;

        while(i < ratings.size())
        {
            if(ratings[i] >= ratings[i-1]){

               cur = ratings[i] == ratings[i-1] ? 1 : cur + 1;

               total += cur;

               i++;

               max = cur;

            }else{

                len = 1;

                //find maximum decreasing subsequence
                while(i < ratings.size() && ratings[i] < ratings[i-1])
                {
                    len++; i++;
                }

                total += max >= len ? (len)*(len-1)/2 : len*(len+1) / 2 - max;

                cur = 1;
            }
        }

        return total;
