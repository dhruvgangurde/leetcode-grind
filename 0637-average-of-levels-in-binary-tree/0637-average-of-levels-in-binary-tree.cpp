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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode* > q;
        q.push(root);
        if (!root) return {};
        while(!q.empty()){
            int size = q.size();
            double temp = size;
            double sum = 0;
            while(size--){
                auto p = q.front();
                q.pop();
                sum += p->val; 
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            result.push_back((double)sum / temp);
        }
        return result;
    }
};