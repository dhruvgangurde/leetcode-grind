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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        if(!root)return {};
        // flag -> false -- we traverse left to right
        // flag -> true -- we traverse right to left
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> level;
            int size = q.size();

            while(size --){
                TreeNode* newNode = q.front();
                q.pop();
                if(newNode->left) q.push(newNode->left);
                if(newNode->right) q.push(newNode->right);
                level.push_back(newNode->val);
            }
            if(flag) reverse(level.begin(), level.end());
            ans.push_back(level);
            flag = !flag;
        }
        return ans;
    }
};