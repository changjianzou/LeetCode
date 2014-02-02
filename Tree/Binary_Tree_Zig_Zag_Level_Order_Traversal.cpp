#include<vector>
#include<stdlib.h>
#include<queue>
#include<algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//using bfs
   vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

       vector<vector<int>> ret;

       if(root == NULL) return ret;

       vector<int> temp;

       queue<TreeNode*> Q;

       Q.push(root);

       int cnt1 = 1, cnt2 = 0;

       TreeNode* cur = NULL;

       bool odd = true;

       while(Q.empty() == false)
       {
           cur = Q.front();

           Q.pop();

           cnt1--;

           temp.push_back(cur->val);

           if(cur->left)
           {
               cnt2++; Q.push(cur->left);
           }

           if(cur->right)
           {
               cnt2++; Q.push(cur->right);
           }

           if(cnt1 == 0)
           {
               if( !odd ) reverse(temp.begin(), temp.end());

               ret.push_back(temp);

               cnt1 = cnt2; cnt2 = 0; temp.clear(); odd = 1^odd;
           }

       }

       return ret;
   }
