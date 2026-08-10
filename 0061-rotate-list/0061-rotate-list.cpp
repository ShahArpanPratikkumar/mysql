class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        tail->next = head;

        k = k % len;
        for (int i = 0; i < len - k - 1; i++) {
            head = head->next;
        }

        ListNode* newHead = head->next;
        head->next = nullptr;

        return newHead;
    }
};