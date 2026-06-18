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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;
        ListNode*p=head;
        ListNode*q=p->next->next;
        while(q!=nullptr && q->next!=nullptr){
            p=p->next;
            q=q->next->next;
        }
        p->next=p->next->next;
        return head;
    }
};