class Solution {
  public:
    Node* constructDLL(vector<int>& arr) {
        int n=arr.size();
        // code here
        Node* head=new Node(arr[0]);
        Node* curr=head;
        for(int i=1;i<n;i++){
            Node* newNode = new Node(arr[i]);
            curr->next=newNode;
            newNode->prev=curr;
            curr=newNode;
        }
        return head;
    }
};