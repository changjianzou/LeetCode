#include<string>
#include<stack>
#include<vector>
#include<iostream>

using namespace std;

bool isNum(string &str)
{
	return (str[0] == '-' && str.size() > 1) ||
			(str[0] >= '0' && str[0] <= '9');
}

int str2num(string& str)
    {
        int num = 0;

        int i = str[0] == '-' ? 1 : 0;

        bool sign = str[0] == '-' ? false : true;

        for(; i < str.size(); i++)
        {
            num *= 10; num += str[i] - '0';
        }

        return sign ? num : -num;
    }

    int evalRPN(vector<string> &tokens) {

        stack<int> workingS;

        int op1 = 0, op2 = 0, num = 0;

        for(int i = 0; i < tokens.size(); i++)
        {
            if( isNum(tokens[i]) )
            {
                workingS.push(str2num(tokens[i]));
            }else{
                op2 = workingS.top(); workingS.pop();
                op1 = workingS.top(); workingS.pop();

                if(tokens[i] == "+"){
                    num = op1 + op2;
                }else if(tokens[i] == "-"){
                    num = op1 - op2;
                }else if(tokens[i] == "*"){
                    num = op1*op2;
                }else{
                    num = op1/op2;
                }

                workingS.push(num);
            }
        }

        return workingS.top();
    }
