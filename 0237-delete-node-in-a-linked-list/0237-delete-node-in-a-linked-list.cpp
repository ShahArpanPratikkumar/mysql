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
    void deleteNode(ListNode* n1) {
        ListNode* temp = n1->next;
        n1->val = temp->val;

        n1->next = temp->next;
        temp->next = NULL;
    }
};