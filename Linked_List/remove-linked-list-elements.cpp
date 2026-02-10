class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp= new ListNode(0);
        temp->next = head;
        ListNode* curr=temp;
        while(curr->next!=NULL){
            if(curr->next->val==val){
                ListNode* del= curr->next;
                curr->next = del->next;
                delete del;

            }else{
                curr= curr->next;
            }
        }
        return temp->next;
        
    }
};