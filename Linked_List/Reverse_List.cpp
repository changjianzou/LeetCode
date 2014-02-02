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
