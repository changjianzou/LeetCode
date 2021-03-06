#include<stdlib.h>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


    //using only constant extra space
    void connect(TreeLinkNode *root) {

        if(root) root->next = NULL;

        TreeLinkNode* dummy = new TreeLinkNode(0);

        TreeLinkNode* p = root, *head = root, *q = dummy;

        while(head)
        {
            p = head; q = dummy;

            while(p){
                if(p->left) { q->next = p->left; q = q->next;}
                if(p->right) { q->next = p->right; q = q->next;}
                p = p->next;
            }

            q->next = NULL;
            head = dummy->next;
            dummy->next = NULL;
        }

    }
