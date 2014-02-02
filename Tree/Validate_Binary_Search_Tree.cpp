#include<stdlib.h>
#include<climits>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    bool isValidBST(TreeNode* root, int &min, int &max)
    {
        if(root == NULL) {min = INT_MAX; max = INT_MIN; return true;}

        min = root->val; max = root->val;

        int left_min = 0, left_max = 0;

        if( ! isValidBST(root->left, left_min, left_max) || left_max >= root->val)
        {
            return false;
        }

        min = min < left_min ? min : left_min;
        max = max > left_max ? max : left_max;

        int right_min = 0, right_max = 0;

        if( ! isValidBST(root->right, right_min, right_max) || right_min <= root->val )
        {
            return false;
        }

        min = min < right_min ? min : right_min;
        max = max > right_max ? max : right_max;

        return true;

    }

    bool isValidBST(TreeNode *root) {

        int min = 0, max = 0;

        return isValidBST(root, min, max);
    }
