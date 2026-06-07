struct Node{
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k,int value)
    {
    key=k;
    val=value;
    next=NULL;
    prev=NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    Node* head,*tail;
    int space;
    LRUCache(int capacity) {
        space=capacity;
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Node* temp)
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }
    void insertNode( Node* num)
    {
        Node *temp;
        temp=head->next;
        head->next=num;
        num->next=temp;
        temp->prev=num;
        num->prev=head;
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* temp=mp[key];
        deleteNode(temp);
        insertNode(temp);
        return temp->val;
            
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* temp=mp[key];
            temp->val=value;
            deleteNode(temp);
            insertNode(temp);
        }
        else{
            if(space!=0 && mp.size()==space)
            {
                Node* temp;
                temp=tail->prev;
                mp.erase(temp->key);
                deleteNode(temp);
            }
            Node *num=new Node(key,value);
            insertNode(num);    
            mp[key]=num;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */