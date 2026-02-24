 //Insert into a Binary Search Tree
/**
 * Definition for a binary tree node.   
 * struct TreeNode {
 *    int val;
 *    TreeNode *left;
 *    TreeNode *right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}  
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        if(root->val>val) root->left=insertIntoBST(root->left,val);
        else root->right=insertIntoBST(root->right,val);
        return root;
    }
};
//iterative approach
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* curr=root;
        while(true){
            if(curr->val>val){
                if(curr->left) curr=curr->left;
                else {
                    curr->left=new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->right) curr=curr->right;
                else {
                    curr->right=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};