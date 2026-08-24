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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Step 1: Securely connect dummy to handle left == 1 edge cases
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* root = head;
        int cnt = 1;

        // Step 2: Advance to the starting point
        while (root) {
            if (cnt == left) {
                break;
            }
            prev = root;
            root = root->next;
            cnt++;
        }      

        // Step 3: Run the localized in-place reversal loop
        ListNode* root2 = root;
        ListNode* prev2 = nullptr; // Initialize to nullptr so the sublist tail is clean
        
        while (root2 && cnt <= right) {
            ListNode* newroot = root2->next;
            root2->next = prev2;
            prev2 = root2;
            root2 = newroot;
            cnt++;
        }

        // Step 4: Reconnect the broken segments securely
        prev->next = prev2; // Link node before sublist to new sublist head
        root->next = root2; // Link original sublist start to remaining tail

        // Step 5: Save the true head before deleting the dummy node
        ListNode* actual_head = dummy->next;
        delete dummy; 
        
        return actual_head;

    }
};