//方法1：将原链表与新链表的节点一一映射
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*,Node*> map;
        Node* cur=head;
        while(cur){
            map[cur]=new Node(cur->val);
            cur=cur->next;
        }
        cur=head;
        while(cur){
            map[cur]->next=map[cur->next];
            map[cur]->random=map[cur->random];
            cur=cur->next;
        }
        return map[head];
    }
};

//方法2：把每个节点在其next复制一份，也是一种映射的方法
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* cur=head;
        while(cur){
            Node* tmp=new Node(cur->val);
            tmp->next=cur->next;
            cur->next=tmp;
            cur=cur->next->next;
        }
        cur=head;
        while(cur){
            if(cur->random) cur->next->random=cur->random->next;
            cur=cur->next->next;
        }
        Node* newhead=head->next,*pre=head;
        cur=newhead;
        while(cur->next){
            pre->next=pre->next->next;//恢复原链表
            cur->next=cur->next->next;
            pre=pre->next;
            cur=cur->next;
        }
        pre->next=nullptr;
        return newhead;
    }
};
