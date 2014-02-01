#include<stdlib.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


    ListNode *rotateRight(ListNode *head, int k) {
        //get the length
        if(head == NULL || head->next == NULL) return head;

        int len = 1;

        ListNode* end = head;

        while(end->next) { end = end->next; len++;}

        k = k%len;

        if(k == 0) return head;

        ListNode* p = head->next, *prev = head;

        for(int i = 0; i < len - k - 1; i++)
        {
            prev = prev->next;
            p = p->next;
        }

        end->next = head;

        prev->next = NULL;

        return p;
    }
