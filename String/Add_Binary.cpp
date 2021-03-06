#include<string>

using namespace std;

string addBinary(string a, string b) {

        int i = a.size() - 1, j = b.size() - 1;

        int carry = 0;

        string sum;

        while(i >= 0 || j >= 0 || carry)
        {
            int val1 = i < 0 ? 0 : a[i] - '0';

            int val2 = j < 0 ? 0 : b[j] - '0';

            sum.insert(0,1, ( val1 + val2 + carry ) % 2 + '0');

            carry = (val1 + val2 + carry) / 2;

            i--; j--;
        }

        return sum;
    }
