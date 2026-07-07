/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // We cannot delete this node directly because we don't have access
        // to the previous node.
        // Instead, copy the value of the next node into the current node,
        // then bypass the next node by updating the current node's next pointer.
        // Effectively, the next node is removed from the list, and the current node now represents the next node's value.
        node->val = node->next->val;
        node->next = node->next->next;
    }
};