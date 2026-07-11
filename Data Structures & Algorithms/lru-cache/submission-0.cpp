class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val): val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    int c=0;
    unordered_map<int,int> valueMap;
    unordered_map<int,Node*> listMap;
    Node* lru = new Node(0);
    Node* mru = new Node(0);
    LRUCache(int capacity) {
        c=capacity;
        lru->next=mru;
        mru->prev=lru;
    }
    
    int get(int key) {
        if(valueMap.contains(key)){
            sendToMRU(listMap[key]);
            return valueMap[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(valueMap.contains(key)){
            sendToMRU(listMap[key]);
            valueMap[key]=value;
        }else{
            valueMap[key]=value;
            listMap[key] = new Node(key);
            if(valueMap.size()>c){
                int key = removeLRU();
                valueMap.erase(key);
            }
            add(listMap[key]);
        }
    }

    void add(Node* node){
        mru->prev->next = node;
        node->prev = mru->prev;
        node->next = mru;
        mru->prev = node;
    }

    int removeLRU(){
        Node* temp = lru->next;
        int key = temp->val;
        temp->next->prev = lru;
        lru->next = temp->next;
        delete temp;
        return key;
    }

    void sendToMRU(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
        add(node);
    }
};
