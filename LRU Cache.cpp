struct Node {
        
        int key;
        int value;
        struct Node *prev;
        struct Node *next;
};
class LRUCache {
public:
    struct Node* head = new Node();
    struct Node* tail = new Node();
    map<int,Node*>node_map;
    int cache_capacity;
    
    LRUCache(int capacity) {
        cache_capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        int result = -1;
        if(node_map.find(key)!=node_map.end()){
            result = node_map[key]->value;
            remove(node_map[key]);
            add(node_map[key]);
        }
        return result;
    }
    
    void put(int key, int value) {
        if(node_map.find(key)!=node_map.end()){
            struct Node* node = node_map[key];
            remove(node);
            node->value = value;
            add(node);
            
        } else {
            if(node_map.size()==cache_capacity){
                node_map.erase(tail->prev->key);
                remove(tail->prev);
            }
            struct Node* new_node = new Node();
            new_node->key = key;
            new_node->value = value;
            node_map[key] = new_node;
            add(new_node);
        }
    }
    
    void add(struct Node* node){
        struct Node* head_next = head->next;
        
        head->next = node;
        
        node->prev = head;
        node->next = head_next;
        
        head_next->prev = node;
    }
    void remove(struct Node* node){
        struct Node* node_next = node->next;
        struct Node* node_prev = node->prev;
        
        node_prev->next = node_next;
        node_next->prev = node_prev;
    }
    
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */