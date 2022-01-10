class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *cur=dummy;
        while(cur->next!=nullptr && cur->next->val!=val){
            cur=cur->next;
        }
        if(cur->next) cur->next=cur->next->next;
        return dummy->next;
    }
};
