#include<vector>

using namespace std;

int maxProfit(vector<int> &prices) {

        int n = prices.size();

        if(n <= 1) return 0;

        vector<int> profit(n,0);

        int min = prices[0];

        for(int i = 1; i < n; i++)
        {
            min = min < prices[i] ? min : prices[i];
            profit[i] = profit[i-1] > prices[i] - min ? profit[i-1] : prices[i] - min;
        }

        int max = 0, max_profit = 0;

        for(int i = n - 1; i >= 1; i--)
        {
            max = max > prices[i] ? max : prices[i];
            if(max_profit < max - prices[i] + profit[i-1]) max_profit = max - prices[i] + profit[i-1];
        }

        max = max > prices[0] ? max : prices[0];

        max_profit = max_profit > max - prices[0] ? max_profit : max - prices[0];

        return max_profit;

    }
