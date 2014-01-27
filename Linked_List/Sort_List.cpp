#include<stdlib.h>
#include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

void partition(ListNode*head, ListNode** left_head, ListNode** left_mid, ListNode** right_mid, ListNode** right_head)
   {
       //virtual nodes
       *left_head = new ListNode(0), *right_head = new ListNode(0), *left_mid = new ListNode(0);

       ListNode* left = *left_head, *right = *right_head, *mid = *left_mid;

       int pivote = head == NULL ? 0 : head->val;

       while(head)
       {
           if(head->val > pivote)
           {
               right->next = head;
               right = right->next;
           }else if(head->val == pivote){
               mid->next = head;
               mid = mid->next;
           }else{
               left->next = head;
               left = left->next;
           }

           head = head->next;
       }

       left->next = NULL; right->next = NULL; mid->next = NULL;

       *left_head = (*left_head)->next;
       *left_mid = (*left_mid)->next;
       *right_mid = (*left_mid) ? mid : NULL;
       *right_head = (*right_head)->next;
   }

   void sortList(ListNode **head, ListNode **end) {

       if(*head == NULL) {*head = NULL; *end = NULL; return;}

       ListNode* left_head = NULL, *left_end = NULL;
       ListNode* left_mid = NULL, *right_mid = NULL;
       ListNode* right_head = NULL, *right_end = NULL;

       //partition
       partition(*head, &left_head, &left_mid, &right_mid, &right_head);

       //recursive
       sortList(&left_head, &left_end);
       sortList(&right_head, &right_end);

       //link
       if(left_end) left_end->next = left_mid;
       right_mid->next = right_head;

       //get head and end
       *head = left_head ? left_head : left_mid;
       *end = right_head ? right_end : right_mid;
   }

   ListNode* sortList(ListNode* head)
   {
       ListNode* end = NULL;

       sortList(&head, &end);

       return head;
   }
