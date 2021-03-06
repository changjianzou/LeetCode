#include<string>
#include<queue>
#include<unordered_set>

using namespace std;
//using BFS
    int ladderLength(string start, string end, unordered_set<string> &dict) {

        if(start == end) return 2;

        queue<string> workingQ;
        unordered_set<string> exist;

        workingQ.push(start);
        exist.insert(start);

        string cur, nbd;

        int cnt1 = 1, cnt2 = 0, len = 2;

        while(workingQ.empty() == false)
        {
            cur = workingQ.front();

            workingQ.pop();

            cnt1--;

            //find all neighbors
            for(int i = 0; i < cur.size(); i++)
            {
                nbd = cur;
                for(int j = 0; j < 26; j++)
                {
                    nbd[i] = 'a' + j;

                    if(exist.find(nbd) == exist.end() && dict.find(nbd) != dict.end())
                    {
                        if(nbd == end) return len;
                        workingQ.push(nbd);
                        exist.insert(nbd);
                        cnt2++;
                    }
                }
            }

            if(cnt1 == 0)
            {
                cnt1 = cnt2;
                len += cnt2 != 0 ? 1 : 0;
                cnt2 = 0;
            }
        }//while

        return 0;
    }
