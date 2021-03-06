#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


 bool myComp(ListNode* l1, ListNode* l2)
 {
     return l1->val > l2->val;
 }


    //using min heap
    ListNode *mergeKLists(vector<ListNode *> &lists) {

        vector<ListNode*>::iterator it = lists.begin();

        while(it != lists.end())
        {
            if(*it == NULL)
                lists.erase(it);
            else
                it++;
        }

        if(lists.size() == 0) return NULL;

        ListNode* virtualHead = new ListNode(0);

        ListNode* cur = virtualHead;

        make_heap(lists.begin(), lists.end(), myComp);

        while(lists.size())
        {
            cur->next = lists[0];

            cur = cur->next;

            pop_heap(lists.begin(), lists.end(), myComp);

            if(lists[lists.size()-1]->next != NULL)
            {
                lists[lists.size()-1] = lists[lists.size()-1]->next;
                push_heap(lists.begin(), lists.end(), myComp);
            }else{
                lists.pop_back();
            }
        }

        return virtualHead->next;
    }
