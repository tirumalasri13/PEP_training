/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        // code here
        if(root==NULL) return -1;
        int rightH = height(root->right);
        int leftH = height(root->left);
        return 1 + max(leftH,rightH);
    }
};