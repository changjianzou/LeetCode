#include<stdlib.h>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


    vector<TreeNode*> generateTrees(int start, int end)
    {
        vector<TreeNode*> ret;

        if(start > end) {ret.push_back(NULL); return ret;}

        for(int i = start; i <= end; i++)
        {

            vector<TreeNode*> left = generateTrees( start, i - 1);

            vector<TreeNode*> right = generateTrees( i+1, end);

            for(int j = 0; j < left.size(); j++)
            {
                for(int k = 0; k < right.size(); k++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ret.push_back(root);
                }
            }
        }

        return ret;
    }

    vector<TreeNode *> generateTrees(int n) {

        return generateTrees( 1, n );
    }

