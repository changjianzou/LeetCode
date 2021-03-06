#include<stdlib.h>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    int search(vector<int> &nums, int s, int e, int target)
    {
        for(int i = s; i <= e; i++)
        {
            if(nums[i] == target) return i;
        }

        return -1;
    }

    TreeNode* build(vector<int> &inorder, int s1, int e1, vector<int> &postorder, int s2, int e2)
    {
        if(s1 > e1 || s2 > e2 ) return NULL;

        int mid = search(inorder, s1, e1, postorder[e2]);

        TreeNode *root = new TreeNode(inorder[mid]);

        root->left = build(inorder, s1, mid - 1, postorder, s2, s2 - s1 +  mid - 1);

        root->right = build(inorder, mid + 1, e1, postorder, s2 - s1 + mid, e2 - 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);

    }
