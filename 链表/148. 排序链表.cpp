class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //因为要求O(n log n)，只能用归并、快排、堆排，这里归并
        int length=0;
        ListNode* tmp=head;
        while(tmp){
            length++;
            tmp=tmp->next;
        }
        return mergesort(head,length);
    }
    ListNode* mergesort(ListNode* head,int length){
        if(length==0 || length==1) return head;
        int length1=length/2,length2=length%2==1?length1+1:length1;
        ListNode* head1=head,*head2=head;
        int i=length1;
        while(i--){
            head2=head2->next;
        }
        head1=mergesort(head1,length1);
        head2=mergesort(head2,length2);
        ListNode* dummy=new ListNode(0);
        ListNode* newhead=dummy;
        int count1=length1,count2=length2;
        while(count1 && count2){
            if(head1->val<head2->val){
                newhead->next=head1;
                head1=head1->next;
                newhead=newhead->next;
                count1--;
            }
            else{
                newhead->next=head2;
                head2=head2->next;
                newhead=newhead->next;
                count2--;
            }
        }
        while(count1){
            newhead->next=head1;
            head1=head1->next;
            newhead=newhead->next;
            count1--;
        } 
        while(count2){
            newhead->next=head2;
            head2=head2->next;
            newhead=newhead->next;
            count2--;
        }
        newhead->next=nullptr;//断尾！关键！链表都要做
        head=dummy->next;
        dummy->next=nullptr;//断尾！关键！链表都要做
        return head;
    }
    
};
