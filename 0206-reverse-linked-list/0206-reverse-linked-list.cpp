/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* before = NULL;
        ListNode* after = NULL;
        if(head == NULL) return NULL;
        while(curr) {
            after = curr->next;
            curr->next = before;
            before = curr;
            curr = after;
        }
        head = before;
        return head;
    }
};