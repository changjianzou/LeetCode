#include<stdlib.h>
#include<stack>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    //using in order traverse
    void recoverTree(TreeNode *root) {

        stack<TreeNode*> s;

        if(root == NULL || ( root->left == NULL && root->right == NULL)) return;

        TreeNode* current = root;

        TreeNode* first = NULL, *second = NULL;

        TreeNode* prev = NULL, *p = NULL;

        while( !s.empty() || current )
        {
            if(current)
            {
                s.push(current);
                current = current->left;
            }
            else{
                current = s.top()->right;

                prev = p;

                p = s.top();

                s.pop();

                if(prev && p->val < prev->val)
                {
                    first = first == NULL ? prev : first;

                    if(second != NULL){
                        second = p; break;
                    }else{
                        second = p;
                    }
                }
            }
        }

        int temp = first->val;
        first->val = second->val;
        second->val = temp;

    }

