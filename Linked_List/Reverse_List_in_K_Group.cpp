#include<stdlib.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


    ListNode* reverse(ListNode*head)
    {
        if( !head ) return head;

        ListNode* dummy = new ListNode(0);

        dummy->next = head;

        ListNode *p = head, *temp = NULL;

        while( p )
        {
            temp = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = temp;
        }

        return dummy->next;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {

        if(head == NULL || k <= 1) return head;

        ListNode* dummy = new ListNode(0); dummy->next = head;

        ListNode *p = dummy->next, *prev = dummy, *temp = NULL;

        int i = 0;

        while( p )
        {
            i++;

            if(i % k == 0)
            {
                temp = p->next;
                p->next = NULL;
                head = prev->next;
                prev->next = reverse(head);
                prev = head;
                prev->next = temp;
            }else{
                temp = p->next;
            }

            p = temp;

        }

        return dummy->next;
    }
