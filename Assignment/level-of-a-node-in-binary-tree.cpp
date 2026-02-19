/*
Structure of the node of the binary tree is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
*/
class Solution {
  public:
    int getLevel(struct Node *node, int target) {
        // code here
        if(node == NULL) return 0;
        queue<Node*> q;
        q.push(node);
        int level = 1;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();
                if(curr->data == target) return level;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            level++;
        }
        return 0;
        
    }
};