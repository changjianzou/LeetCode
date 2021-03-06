#include<stdlib.h>
#include<iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* flatten2(TreeNode* root)
    {
        if(root == NULL) {
            return NULL;
        }

        TreeNode* lEnd = flatten2(root->left);

        TreeNode* rEnd = flatten2(root->right);

        if(lEnd) lEnd->right = root->right;

        root->right =  root->left != NULL ?  root->left: root->right;

        root->left = NULL;

        if(rEnd != NULL) return rEnd;
        else if(lEnd != NULL) return lEnd;
        else return root;

    }

    void flatten(TreeNode *root) {

        flatten2(root);

    }


    void test()
    {
    	TreeNode *root = new TreeNode(1);
    	root->left = new TreeNode(2);
    	root->right = new TreeNode(3);
    	flatten(root);

    	while(root)
    	{
    		cout<<root->val<<" ";
    		root = root->right;
    	}
    	cout<<endl;
    }

    int main()
    {
    	test();
    }
