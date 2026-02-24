//Recurssive approach
/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(root==NULL) return false;
        if(key==root->data) return true;
        if(key>root->data) return search(root->right,key);
        else return search(root->left,key);
    }
};

//Iterative approach
class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        bool ans = false;
        while(root!=NULL){
            if(root->data=key){
                ans = true;
            }
            else if(key>root->data){
                root=root->right;
            }
            else
            root=root->left;
            
        }
        return ans;
     s
    }
}