#include<string>
#include<vector>
#include<climits>

using namespace std;

int minCut(string s) {

      if(s.size() == 0) return 0;

      vector<int> min(s.size(), INT_MAX);

      vector<bool> P(s.size(), true);

      for(int i = 0; i < s.size(); i++)
      {
          for(int j = 0; j <= i; j++)
          {
              P[j] = j == i ? true : (s[j] == s[i]) && P[j+1];
          }

          for(int j = 0; j <= i; j++)
          {
              if(P[0]){ min[i] = 0; break;}

              if(j && P[j])
              {
                  min[i] = min[i] < min[j-1] + 1 ? min[i] : min[j-1] + 1;
              }
          }

      }

      return min[s.size() - 1];
  }
