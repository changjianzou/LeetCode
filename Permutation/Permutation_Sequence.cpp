#include<vector>
#include<string>

using namespace std;

void preComp(vector<int> &factorial, int n)
    {
        factorial[0] = 1;

        for(int i = 1; i <= n; i++)
        {
            factorial[i] = i*factorial[i-1];
        }
    }

    string getPermutation(int n, int k) {

        vector<int> factorial(10,0);

        preComp(factorial, 9);

        vector<int> num(n,0);

        for(int i = 0; i < n; i ++) num[i] = i+1;

        int temp = 0;

        string perm;

        for(int i = 0; i < n; i++)
        {
            temp = (k-1) / factorial[n-i-1];
            k -= temp*factorial[n-i-1];
            perm.push_back('0' + num[temp]);
            num.erase(num.begin() + temp);
        }

        return perm;
    }
