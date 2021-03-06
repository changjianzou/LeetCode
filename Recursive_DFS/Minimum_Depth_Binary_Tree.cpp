#include<stdlib.h>
#include<climits>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    int minDepth2(TreeNode* root)
    {
        if( root->left == NULL && root->right == NULL) return 1;

        int minD = INT_MAX;

        if(root->left != NULL)
        {
            int lMin =  minDepth2(root->left);
            minD = minD < lMin ? minD : lMin;
        }

        if(root->right != NULL)
        {
            int rMin =  minDepth2(root->right);
            minD = minD < rMin ? minD : rMin;
        }

        return 1 + minD;
    }

    int minDepth(TreeNode *root) {

        if(root == NULL) return 0;

        return minDepth2(root);

    }
