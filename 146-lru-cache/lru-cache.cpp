class LRUCache {
public:
    struct LL{
        int k, v;
        struct LL* next, *prev;
        LL(){
                k = -1;
                v = -1;
                next = NULL;
                prev = NULL;
        }
    };

    int SIZE = 0, cap = 0;
    map<int, struct LL*>mp;
    struct LL* front = NULL, *rear = NULL;


    LRUCache(int capacity) {
        SIZE = capacity;
    }
    
    int get(int key) {
        int res;
        if(mp[key] == NULL) res = -1;
        else {
            res = mp[key]->v;
            if(mp[key] == rear){
                if(mp[key] != front){
                    LL *temp = rear;
                    rear->prev->next = NULL;
                    rear = rear->prev;
                    
                    front->prev = temp;
                    temp->next = front;
                    front = temp;
                    front->prev = NULL;
                }
            }
            else if(mp[key] != front){
                LL*temp = mp[key];
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                
                front->prev = temp;
                temp->next = front;
                front = temp;
                front->prev = NULL;
            }
        }
        return res;
    }
    
    void put(int key, int value) {
        if(mp[key] == NULL){
            LL*temp = new LL();
            temp->k = key;
            temp->v = value;
            
            if(cap == SIZE){
                temp->next = front;
                front->prev = temp;
                front = front->prev;
                
                rear->prev->next = NULL;
                mp[rear->k] = NULL;
                rear = rear->prev;
            }
            else{
                if(front == NULL){
                    front = temp;
                    rear = temp;
                }
                else{
                    front->prev = temp;
                    temp->next = front;
                    front = temp;
                }
                cap++;
            }
            mp[key] = temp;
        }
        else{
            mp[key]->v = value;
            if(mp[key] == rear){
                if(mp[key] != front){
                    LL *temp = rear;
                    rear->prev->next = NULL;
                    rear = rear->prev;
                    
                    front->prev = temp;
                    temp->next = front;
                    front = temp;
                    front->prev = NULL;
                }
            }
            else if(mp[key] != front){
                LL*temp = mp[key];
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                
                front->prev = temp;
                temp->next = front;
                front = temp;
                front->prev = NULL;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */