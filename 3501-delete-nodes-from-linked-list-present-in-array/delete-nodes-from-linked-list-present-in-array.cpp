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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Create a set for O(1) lookups
        unordered_set<int> toRemove(nums.begin(), nums.end());
        
        // Remove nodes from beginning that need to be removed
        while (head != nullptr && toRemove.count(head->val)) {
            head = head->next;
        }
        
        // If all nodes were removed
        if (head == nullptr) {
            return nullptr;
        }
        
        // Traverse the rest of the list
        ListNode* current = head;
        while (current->next != nullptr) {
            if (toRemove.count(current->next->val)) {
                // Skip the next node
                current->next = current->next->next;
            } else {
                // Move to next node
                current = current->next;
            }
        }
        
        return head;
    }
};