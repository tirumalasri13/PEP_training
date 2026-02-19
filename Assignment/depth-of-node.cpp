/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
     void solve(Node* root, int level, int &ans) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            if(level % 2 == 1) {
                ans = max(ans, level);
            }
            return;
        }

        solve(root->left, level + 1, ans);
        solve(root->right, level + 1, ans);
    }
    int depthOfOddLeaf(Node *root) {
        int ans = 0;
        solve(root, 1, ans);
        return ans;
        // code here
        
    }
};