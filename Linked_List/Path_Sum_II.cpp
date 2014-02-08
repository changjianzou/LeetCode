#include<stdlib.h>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    void pathSum(TreeNode* root, vector<int> &path, int sum, vector<vector<int>> &ret)
    {
        if(root == NULL) return;

        path.push_back(root->val);

        sum -= root->val;

        if(root->left == NULL && root->right == NULL)
        {
            if(!sum) ret.push_back(path);
            path.pop_back();
            return;
        }

        pathSum(root->left, path, sum, ret);

        pathSum(root->right, path, sum, ret);

        path.pop_back();
    }

    vector<vector<int> > pathSum(TreeNode *root, int sum) {

        vector<int> path;

        vector<vector<int>> ret;

        pathSum(root, path, sum, ret);

        return ret;

    }
};
