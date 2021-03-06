#include<stdlib.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


    ListNode *deleteDuplicates(ListNode *head) {

        if(head == NULL) return head;

        ListNode* virtualHead = new ListNode(0);

        virtualHead->next = head;

        ListNode* temp = virtualHead, *prev = head, *p = head->next;

        int cnt = 1;

        while( p )
        {
            if(p->val == prev->val )
            {
                temp->next = p->next; cnt++;
            }

            else
            {
                if(cnt > 1){
                    temp->next = p; cnt = 1;
                }else{
                    temp = prev;
                }
            }

            prev = p;
            p = p->next;
        }

        return virtualHead->next;

    }
