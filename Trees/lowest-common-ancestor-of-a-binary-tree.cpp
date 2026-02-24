/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//DFS..
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left != NULL && right != NULL) return root;
        if(left != NULL) return left;
        return right;
        
    }
};
//BFS..
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q1;
        q1.push(root);
        parent[root] = NULL;
        while(!q1.empty()){
            TreeNode* node = q1.front();
            q1.pop();
            if(node->left != NULL){
                parent[node->left] = node;
                q1.push(node->left);
            }
            if(node->right != NULL){
                parent[node->right] = node;
                q1.push(node->right);
            }
        }
        unordered_set<TreeNode*> s;
        while(p != NULL){
            s.insert(p);
            p = parent[p];
        }
        while(q != NULL){
            if(s.count(q)) return q;
            q = parent[q];
        }
        return NULL;
    }
};