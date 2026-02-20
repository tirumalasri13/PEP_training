//108. Convert Sorted Array to Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1,nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};
//optimized approach
/**     
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* build(vector<int>& nums, int left, int right){
        if(left>right) return NULL;
        int mid = left+(right-left)/2;
        TreeNode* root= new TreeNode(nums[mid]);
        root->left=build(nums,left,mid-1);
        root->right=build(nums,mid+1,right);
        return root; 
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);    
    }
};