#include<stdlib.h>
#include<climits>

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    void maxPathSum(TreeNode* root, int &max, int &max_path)
    {
        max_path = 0;

        if(root == NULL) {return;}

        //update max path sum
        int left_max_path = 0;

        maxPathSum(root->left, max, left_max_path);

        max_path = left_max_path > 0 ? left_max_path + root->val : root->val;

        int right_max_path = 0;

        maxPathSum(root->right, max, right_max_path);

        max_path = max_path > right_max_path + root->val ? max_path : right_max_path + root->val;

        //update max
        int sum = root->val;
        sum += left_max_path > 0 ? left_max_path : 0;
        sum += right_max_path > 0 ? right_max_path : 0;

        max = max > sum ? max : sum;
    }

    int maxPathSum(TreeNode *root) {

        int max = INT_MIN, max_path = 0;

        maxPathSum(root, max, max_path);

        return max;
    }


