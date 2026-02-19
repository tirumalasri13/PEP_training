/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(Node *root, int k) {
        // Your code here
        vector<int> ans;
        if(root == NULL) return ans;

        queue<Node*> q;
        q.push(root);

        int level = 0;

        while(!q.empty()) {
            int n = q.size();

            if(level == k) {
                while(!q.empty()) {
                    ans.push_back(q.front()->data);
                    q.pop();
                }
                return ans;
            }

            for(int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            level++;
        }

        return ans;
    }
};