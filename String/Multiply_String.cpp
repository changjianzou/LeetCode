#include<string>

using namespace std;

void reverse(string& num)
    {
        int n = num.size(); char c = '0';

        for(int i = 0; i < n / 2; i++)
        {
            c = num[i];
            num[i] = num[n-1-i];
            num[n-1-i] = c;
        }
    }

    string multiply(string num1, string num2) {

        reverse(num1);

        reverse(num2);

        string product;

        int temp = 0, carry = 0;

        int i = 0, j = 0;

        for(i = 0; i <= num1.size() + num2.size() - 2; i++)
        {
            temp = carry;

            j = i - num2.size() + 1;

            j = j > 0 ? j : 0;

            for(; j <= i && j < num1.size(); j++)
            {
                temp += (num1[j] - '0')*(num2[i-j] - '0');
            }

            carry = temp / 10;

            product.push_back(temp % 10 + '0');
        }

        if(carry)
        {
            product.push_back(carry + '0');
        }

        reverse(product);

        while(product.size() > 1 && product[0] == '0')
        {
            product.erase(product.begin());
        }


        return product;
    }
