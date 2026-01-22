class LRUCache {
private:
    struct Node {
        int key, val;
        struct Node* next=NULL;
        struct Node* prev=NULL;
    };
    class LinkedList {
        Node* head=NULL;
        Node* tail=NULL;
        int count=0;
    public: 
        void push_front(Node* newNode) {
            newNode->next=NULL;
            newNode->prev=NULL;
            if(head==NULL) { 
                tail=newNode;
            } else {
                head->prev=newNode;
                newNode->next=head;
            }
            head=newNode;
            count++;
        }

        void unlink(Node* curNode) {
            if(curNode->next) {
                curNode->next->prev=curNode->prev;
            }
            if(curNode->prev) {
                curNode->prev->next=curNode->next;
            }
            if(curNode==head) {
                head=head->next;
            }
            if(curNode==tail) {
                tail=tail->prev;
            } 
            count--;
        }

        void remove(Node* curNode) {
            unlink(curNode); 
            delete curNode;
        }

        int pop_back() {
            int key=tail->key;
            remove(tail); 
            return key;
        };   

        int size() {
            return count;
        }
    };
    unordered_map<int, Node*> mp;
    int cap;
    LinkedList lst;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) {
            return -1;
        }
        lst.unlink(mp[key]);
        lst.push_front(mp[key]);
        return mp[key]->val;        
    } 

    Node* createNode(int key, int val) {
        Node* newNode=new Node;
        newNode->key=key;
        newNode->val=val;
        newNode->next=NULL;
        newNode->prev=NULL;
        return newNode;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()) {
            mp[key]->val=value;
            lst.unlink(mp[key]);
            lst.push_front(mp[key]);
        } else {
            if(cap==lst.size()) {
                mp.erase(lst.pop_back());
            }
            Node* newNode=createNode(key, value);
            lst.push_front(newNode);
            mp[key]=newNode;
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
