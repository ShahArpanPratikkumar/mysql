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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        int firstCritical = -1;
        int prevCritical = -1;
        int minDistance = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;

            // Check if current node is a local maxima or minima
            if ((curr->val > prev->val && curr->val > nextNode->val) ||
                (curr->val < prev->val && curr->val < nextNode->val)) {
                
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minDistance = min(minDistance, index - prevCritical);
                }
                prevCritical = index;
            }

            prev = curr;
            curr = nextNode;
            index++;
        }

        // Return [-1, -1] if fewer than 2 critical points are found
        if (firstCritical == -1 || firstCritical == prevCritical) {
            return {-1, -1};
        }

        int maxDistance = prevCritical - firstCritical;
        return {minDistance, maxDistance};
    }
};