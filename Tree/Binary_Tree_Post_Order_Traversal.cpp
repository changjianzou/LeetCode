#include<stdlib.h>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    //using the idea of iterator
    vector<int> postorderTraversal(TreeNode *root) {

        stack<TreeNode*> s;

        vector<int> ret;

        if(root == NULL) return ret;

        s.push(root);

        TreeNode* curr = root, *prev = NULL;

        while(curr->left){
            s.push(curr->left);
            curr = curr->left;
        }

        while( !s.empty())
        {
            curr = s.top();

            while(curr->right != NULL && curr->right != prev)
            {
                s.push(curr->right);
                curr = curr->right;
                while(curr->left != NULL){
                    s.push(curr->left);
                    curr = curr->left;
                }
            }

            ret.push_back(curr->val);
            prev = curr;
            s.pop();

        }

        return ret;
    }
