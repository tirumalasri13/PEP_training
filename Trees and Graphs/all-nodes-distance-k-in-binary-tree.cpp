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
    void pushParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front->left){
                mp[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                mp[front->right]=front;
                q.push(front->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        unordered_set<TreeNode*>visited;
        queue<TreeNode*> q;
        vector<int> ans;
        visited.insert(target);
        pushParents(root,mp);
        q.push(target);
        int curr_dist=0;
        while(!q.empty()){
            if(curr_dist==k) break;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* front=q.front();
                q.pop();
                if(front->left && !visited.count(front->left)) {
                    q.push(front->left);
                    visited.insert(front->left);
                }
                if(front->right && !visited.count(front->right)) {
                    q.push(front->right);
                    visited.insert(front->right);
                }
                if(mp.count(front) && !visited.count(mp[front]) ){
                    q.push(mp[front]);
                    visited.insert(mp[front]);
                }
            }
            curr_dist++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

        
    }
};