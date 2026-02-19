/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root==NULL) return ans;
        int HD = 0;
        map<int,int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, HD});
        while(!q.empty()){
            Node* front = q.front().first;
            int hd = q.front().second;
            q.pop();
            if(mp.find(hd)==mp.end()){
                mp[hd] = front->data;
            }
            if(front->left) q.push({front->left, hd-1});
            if(front->right) q.push({front->right, hd+1});
            
        }
        for(auto it:mp){
                ans.push_back(it.second);
        }
        return ans;
    }
};