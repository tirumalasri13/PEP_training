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


//bfs
class Solution {
  public:
    int height(Node* root) {
        if(root == NULL) return -1;
        queue<Node*> q;
        q.push(root);
        int h = -1;
        while(!q.empty()) {
            int size = q.size();
            h++;
            for(int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return h;
    }
};