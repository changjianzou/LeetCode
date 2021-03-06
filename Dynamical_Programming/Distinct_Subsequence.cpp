#include<string>
#include<vector>
#include<iostream>

using namespace std;

//using DP
  int numDistinct(string S, string T) {

      vector<int> DP(S.size() + 1, 0);

      int temp1 = 0, temp2 = 0;

      for(int i = 0;  i < T.size(); i++)
      {
          temp1 = 0, temp2 = 0;
          for(int j = 1; j <= S.size(); j++)
          {
              temp2 = temp1;

              temp1 = DP[j];

              DP[j] = DP[j-1];

              if(S[j-1] == T[i])  DP[j] += i == 0 ?  1 : temp2;
          }

      }

      return DP[S.size()];
  }
