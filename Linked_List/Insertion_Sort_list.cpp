#include<stdlib.h>


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


    void insert(ListNode* head, ListNode* node)
    {
        ListNode* prev = head, *p = head->next;

        while(p)
        {
            if(p->val <= node->val)
            {
                prev = p;
                p = p->next;
            }else{
                prev->next = node;
                node->next = p;
                break;
            }
        }

        if(!p) {prev->next = node; node->next = NULL;}
    }

    ListNode *insertionSortList(ListNode *head) {

        ListNode* dummy = new ListNode(0);

        ListNode* temp = NULL;

        while( head )
        {
            temp = head->next;

            insert(dummy, head);

            head = temp;
        }

        return dummy->next;
    }
