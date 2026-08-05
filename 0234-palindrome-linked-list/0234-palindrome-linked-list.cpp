class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> values;
        
        // Copy linked list values into a vector
        ListNode* current = head;
        while (current != nullptr) {
            values.push_back(current->val);
            current = current->next;
        }
        
        // Use two pointers to check for palindrome
        int left = 0;
        int right = values.size() - 1;
        while (left < right) {
            if (values[left] != values[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};