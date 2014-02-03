#include<stack>
#include<string>

using namespace std;

bool match(char c1, char c2)
    {
        return ( c1 == '(' && c2 == ')' ) || c1 == ( '[' && c2 == ']' ) || ( c1 == '{' && c2 == '}' );
    }

    bool isValid(string s) {

        stack<char> workingS;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                workingS.push(s[i]);
            }else{
                if( workingS.empty() || !match(workingS.top(), s[i]) ) return false;
                workingS.pop();
            }

        }

        return workingS.empty();
    }
