#include<stdlib.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


    ListNode *partition(ListNode *head, int x) {

        ListNode* dummy1 = new ListNode(0),*dummy2 = new ListNode(0);

        ListNode* p = dummy1, *q = dummy2;

        while( head )
        {
            if( head->val < x )
            {
                p->next = head;
                p = p->next;
            }
            else{
                q->next = head;
                q = q->next;
            }

            head = head->next;
        }

        p->next = dummy2->next;
        q->next = NULL;

        return dummy1->next;
    }
