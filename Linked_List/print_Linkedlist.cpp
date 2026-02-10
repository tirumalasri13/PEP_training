class Solution {
  public:
    vector<int> printList(Node *head) {
        // code here
        vector<int> ans;
        while(head != NULL) {
            ans.push_back(head->data);
            head = head->next;
        }
        return ans;
    }
};