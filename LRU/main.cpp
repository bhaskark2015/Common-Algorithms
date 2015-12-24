#include<unordered_map>
#include<iostream>
#include<cstdlib>
using namespace std;
class LRUCache
{
public:
    LRUCache(int);
    int get(int);
    void set(int,int);
};

struct node {
    int key;
    int val;
    struct node * prev;
    struct node * next;
};
struct node * head = NULL;
unordered_map<int, struct node * > hash;
int capacity = 0;
int cachesize = 0;
LRUCache::LRUCache(int capacity) {
    ::capacity = capacity;
    ::cachesize = 0;
    ::hash.erase(::hash.begin(), ::hash.end());
    ::head = NULL;
}
void printlist(struct node * head) {
    cout << "the list is:";
    if (head) {
        struct node * temp = head;
        cout << head->key;
        while ((temp = temp ->next) != head) cout << " " << temp->key;
        cout << endl;
    }
    //  cout<<"head is null"<<endl;  
}
int LRUCache::get(int key) {
#ifdef DEBUG
    cout << "GET " << key << endl;
#endif
    if (::hash.count(key) > 0) {
        struct node * llnode = ::hash[key];
        if (llnode != head) {
            //delete the node 
            llnode->prev->next = llnode->next;
            llnode->next->prev = llnode->prev;
            //insert the node in position of head and make it as head
            llnode->next = head;
            llnode->prev = head->prev;
            head->prev->next = llnode;
            head->prev = llnode;
            head = llnode;
        }
#ifdef DEBUG
        printlist(head);
#endif
        return llnode->val;
    }
    else return -1;
}
void LRUCache::set(int key, int value) {
    if (::hash.count(key) > 0) {
        //key already exists in cache just update the key value
        ::hash[key]->val = value;
        get(key);
    } else {
        if (::cachesize<::capacity) {
            struct node * temp = (struct node *) malloc(sizeof (struct node));
            temp->val = value;
            temp->key = key;
            //insert this at the head
            if (head == NULL) {
                head = temp;
                temp->next = temp;
                temp->prev = temp;
            } else {
                temp->next = head;
                temp->prev = head->prev;
                //now displace head
                head->prev->next = temp;
                head->prev = temp;
                head = temp;
            }
            ::hash[key] = temp;
            ::cachesize++;
        } else {
            //remove least recently used node;
#ifdef DEBUG
            cout << endl << "removing entry " << head->prev->key << endl;
#endif
            ::hash.erase(head->prev->key);
            head = head->prev;
            head->key = key;
            head->val = value;
            ::hash[key] = head;
        }
    }
#ifdef DEBUG
    cout << "set " << key << " " << value << endl;
    printlist(head);
#endif
}


int main()
{
    return 0;
}