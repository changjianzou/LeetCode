#include<stdlib.h>

struct ListNode {
     int val;
     ListNode *next;
 	 ListNode(int x) : val(x), next(NULL) {}
};

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode* virtualHead = new ListNode(0);

        ListNode* l = virtualHead;

        int carry = 0;

        while(l1 && l2)
        {
            l->next = new ListNode( (l1->val + l2->val + carry ) % 10);

            carry = (l1->val + l2->val + carry ) / 10;

            l = l->next; l1 = l1->next; l2 = l2->next;
        }

        ListNode* p = l1 != NULL ? l1 : l2;

        while(p)
        {
            l->next = new ListNode( ( p->val + carry ) % 10);

            carry = (p->val + carry ) / 10;

            l = l->next;    p = p->next;
        }

        if(carry)
        {
            l->next = new ListNode(carry);
        }

        return virtualHead->next;
    }

