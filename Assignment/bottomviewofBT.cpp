//bottom view of binary tree
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
    vector<int> bottomView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            TreeNode* node=front.first;
            int hd=front.second;
            mp[hd]=node->val;
            if(node->left) q.push({node->left,hd-1});
            if(node->right) q.push({node->right,hd+1});
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};