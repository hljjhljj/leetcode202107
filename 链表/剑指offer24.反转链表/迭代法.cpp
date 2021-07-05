/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* pre=nullptr, *cur=head;
        while(cur !=nullptr ){
            ListNode* temp=cur->next;
            cur->next = pre;
            pre=cur;
            cur=temp;
        }
        return pre;

    }
};
