class Solution {
public:
    void append(int value, ListNode* &tail){
        tail->next = new ListNode(value);
        tail = tail->next;
    }

    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr)
            return nullptr;

        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Odd positions
        ListNode* odd = head;
        while(odd){
            append(odd->val, tail);

            if(odd->next && odd->next->next)
                odd = odd->next->next;
            else
                break;
        }

        // Even positions
        ListNode* even = head->next;
        while(even){
            append(even->val, tail);

            if(even->next && even->next->next)
                even = even->next->next;
            else
                break;
        }

        return dummy->next;
    }
};