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

        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int firstIndex = -1;
        int prevIndex = -1;
        int minDistance = INT_MAX;
        int index = 1;

        while (curr->next != nullptr) {
            // Check if current node is a local maxima or local minima
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                
                if (firstIndex == -1) {
                    firstIndex = index;
                } else {
                    minDistance = min(minDistance, index - prevIndex);
                }
                prevIndex = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // If fewer than two critical points were found
        if (firstIndex == -1 || prevIndex == firstIndex) {
            return {-1, -1};
        }

        int maxDistance = prevIndex - firstIndex;
        return {minDistance, maxDistance};
    }
};