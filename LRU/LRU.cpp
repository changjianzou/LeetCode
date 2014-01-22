#include<stdlib.h>
#include<map>

using namespace std;

class LRUCache{
private:

    struct LinkedNode{
        int key;
        int val;
        LinkedNode* next;
        LinkedNode* prev;
        LinkedNode(int x, int y): key(x), val(y), next(NULL), prev(NULL){}
    };

    LinkedNode* head;
    LinkedNode* rear;

    map<int,LinkedNode*> mymap;
    int cap;
    int size;

private:
    void deleteNode(LinkedNode* cur){
        //delete the current node
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    void insert2Head(LinkedNode* cur){
        //insert to the beginning of the linked list
        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        cur->prev = head;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new LinkedNode(0,0);
        rear = new LinkedNode(0,0);
        head->next = rear;
        rear->prev = head;
    }

    int get(int key) {
        LinkedNode* cur = NULL;

        if(mymap.find(key) == mymap.end()){
            return -1;
        }
        else
        {
            cur = mymap[key];
            deleteNode(cur);
            insert2Head(cur);
            return cur->val;
        }
    }

    void set(int key, int value) {
        LinkedNode* cur = NULL;

        if(mymap.find(key) == mymap.end())
        {
            cur = new LinkedNode(key, value);
            mymap.insert(pair<int,LinkedNode*>(key,cur));
            insert2Head(cur);
            size++;

            if(size > cap)
            {
                size--;
                mymap.erase(rear->prev->key);
                deleteNode(rear->prev);
            }
        }
        else
        {
            cur = mymap[key];
            cur->val = value;
            deleteNode(cur);
            insert2Head(cur);
        }
    }
};



