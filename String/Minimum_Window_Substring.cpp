#include<string>
#include<queue>
#include<iostream>
#include<climits>

using namespace std;

string minWindow(string S, string T) {

        unsigned cnt_s[256] = {0};

        unsigned cnt_t[256] = {0};

        unsigned i = 0;

        for(i = 0; i < T.size(); i++) cnt_t[(unsigned)T[i]]++;

        queue<int> workingQ;

        unsigned len = INT_MAX, cnt = 0;
        int start = -1;

        //get the minimum window using queue
        for(i = 0; i < S.size(); i++)
        {
            if(cnt_t[(unsigned)S[i]] == 0) continue;

            cnt_s[(unsigned)S[i]]++;

            workingQ.push(i);

            if(cnt_s[(unsigned)S[i]] <= cnt_t[(unsigned)S[i]]) cnt++;

            while(cnt_s[(unsigned)S[workingQ.front()]] > cnt_t[(unsigned)S[workingQ.front()]])
            {
                cnt_s[(unsigned)S[workingQ.front()]]--;
                workingQ.pop();
            }

            if(cnt == T.size() && len > i - workingQ.front() + 1)
            {
                len = i - workingQ.front() + 1;
                start = workingQ.front();
            }
        }

        return len == INT_MAX ? "" : S.substr(start,len);
    }

//void test()
//{
//	string S("ADOBECODEBANC");
//	string T("ABC");
//	cout<<minWindow(S, T)<<endl;
//}
//
//int main()
//{
//	test();
//}
