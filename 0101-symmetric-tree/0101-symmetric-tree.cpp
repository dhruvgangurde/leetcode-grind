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

/*
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

 /*//recursive
class Solution {
public:
    bool isMirror(TreeNode* n1, TreeNode* n2){
        if(n1 == NULL && n2 == NULL){
            return true;
        }
        if(n1 == NULL || n2 == NULL){
            return false;
        }
        return n1->val == n2->val && isMirror(n1->left, n2->right) && isMirror(n1->right, n2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};
*/
// iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root->left, root->right});
        while(!q.empty()) {
            auto [left, right] = q.front();
            q.pop();
            // both are NULL
            if(left == NULL && right == NULL)
                continue;
            // one is NULL
            if(left == NULL || right == NULL)
                return false;
            // values dont match
            if(left->val != right->val)
                return false;
            // push mirror children
            q.push({left->left, right->right});
            q.push({left->right, right->left});
        }
        return true;
    }
};