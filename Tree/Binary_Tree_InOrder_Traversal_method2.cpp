#include<vector>
#include<stdlib.h>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    vector<int> inorderTraversal(TreeNode *root) {

        vector<int> ret;

        if(root == NULL) return ret;

        stack<TreeNode*> s;

        s.push(root);

        TreeNode* curr = root;

        while(curr->left)
        {
            s.push(curr->left);
            curr = curr->left;
        }

        while( !s.empty() )
        {
            curr = s.top();
            ret.push_back(curr->val);
            s.pop();

            if(curr->right){
                s.push(curr->right);
                curr = curr->right;
                while(curr->left){
                    s.push(curr->left);
                    curr = curr->left;
                }
            }
        }

        return ret;
    }
