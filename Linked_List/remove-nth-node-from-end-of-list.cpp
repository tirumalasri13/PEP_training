class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* curr=head;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        if(n==len){
            return head->next;
        }
        curr=head;
        if(head==NULL || head->next==NULL) return NULL;
        for(int i=0;i<len-n-1;i++){
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};