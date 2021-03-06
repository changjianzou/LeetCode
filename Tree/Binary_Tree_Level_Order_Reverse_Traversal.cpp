#include<stdlib.h>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    int height(TreeNode* root)
    {
       if(root == NULL) return 0;
       int h1 = height(root->left) + 1, h2 = height(root->right) + 1;
       return h1 > h2 ? h1 : h2;
    }

    void dfs(TreeNode* root, int level, vector<vector<int>> &ret)
    {
        if(!root) return;

        dfs(root->left, level - 1, ret);

        dfs(root->right, level - 1, ret);

        ret[level - 1].push_back(root->val);
    }

    //using dfs
    vector<vector<int> > levelOrderBottom(TreeNode *root){
        int h = height(root);
        vector<vector<int>> ret(h, vector<int>());
        dfs(root, h, ret);
        return ret;
    }
