struct Node {
    int key;
    int val;
    int freq;
    Node* prev;
    Node* next;
    Node () : key(-1), val(-1), freq(0), prev(nullptr), next(nullptr) {}
    Node (int _k, int _v) : key(_k), val(_v), freq(1), prev(nullptr), next(nullptr) {}
};
struct FreqList {
    int freq;
    Node* vhead;
    Node* vtail;
    
    FreqList (int _f) : freq(_f), vhead(new Node()), vtail(new Node()) {
        vhead->next = vtail;
        vtail->prev = vhead;
    }
};

class LFUCache {
private:
    unordered_map<int, Node*> occ;
    unordered_map<int, FreqList*> freq_map;
    int sz;
    int min_freq;

    bool empty(FreqList* l) {
        return l->vhead->next == l->vtail ? true : false;
    }
    
    void deleteNode (Node* t) {
        t->prev->next = t->next;
        t->next->prev = t->prev;
    }
    
    //把节点t，添加到节点t对应频率链表的头部
    void addHead (Node* t) {
        int freq = t->freq;
        if (freq_map.find(freq) == freq_map.end()) {
            freq_map[freq] = new FreqList(freq);
        }
        FreqList* l = freq_map[freq];
        t->next = l->vhead->next;
        l->vhead->next->prev = t;
        t->prev = l->vhead;
        l->vhead->next = t;
    }
    
    //删除最小频率链表的最后一个节点
    void popTail () {
        Node* t = freq_map[min_freq]->vtail->prev;
        deleteNode(t);
        occ.erase(t->key);
    }
    
public:
    LFUCache (int capacity) : sz(capacity) {}
    
    
    int get (int key) {
        int res = -1;
        if (occ.find(key) != occ.end()) {
            Node* t = occ[key];
            res = t->val;
            deleteNode(t);
            t->freq++;
            if (empty(freq_map[min_freq])) min_freq++;
            addHead(t);
        }
        return res;
    }
    
    void put (int key, int value) {
        if (sz == 0) return;
        if (get(key) != -1) {
            //get它的时候已经把它频率增加一次并移动到合适的链表了
            occ[key]->val = value;
        }
        else {
            if (occ.size() == sz) {
                popTail();
            }
            Node* t = new Node(key, value);
            occ[key] = t;
            min_freq = 1;//新插入的 频率一定最少, 为1
            addHead(t);
        }
    }
};
