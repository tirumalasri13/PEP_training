//938. Range sum of BST
//recursive approach
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:   int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        if(root->val<low) return rangeSumBST(root->right,low,high);
        else if(root->val>high) return rangeSumBST(root->left,low,high);
        else return root->val+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    }
};
//iterative approach
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:   int rangeSumBST(TreeNode* root, int low, int high) {        
        int sum = 0;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node!=NULL){
                if(node->val>=low && node->val<=high) sum+=node->val;
                if(node->val>low) st.push(node->left);
                if(node->val<high) st.push(node->right);
            }
        }
        return sum;
    }
};