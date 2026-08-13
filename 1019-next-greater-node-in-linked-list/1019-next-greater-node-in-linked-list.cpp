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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> values;
        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }

        int n = values.size();
        vector<int> answer(n, 0);
        stack<int> st; 
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && values[st.top()] < values[i]) {
                answer[st.top()] = values[i];
                st.pop();
            }
            st.push(i);
        }

        return answer;
    }
};