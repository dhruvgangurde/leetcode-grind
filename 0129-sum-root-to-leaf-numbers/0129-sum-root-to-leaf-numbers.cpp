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
    int DFS(TreeNode* root, int value){
        if(root == NULL)return 0;
        value = value*10 + root->val;
        if(!root->left && !root->right){
            return value;
        }
        return DFS(root->left, value) + DFS(root->right, value);
    }
    int sumNumbers(TreeNode* root) {
        int value = 0;
        return DFS(root, value);
    }
};