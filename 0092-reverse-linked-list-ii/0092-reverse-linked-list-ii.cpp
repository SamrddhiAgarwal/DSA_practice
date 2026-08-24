// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if (!head || left == right) return head;

//         // Step 1: Securely connect dummy to handle left == 1 edge cases
//         ListNode* dummy = new ListNode(0, head);
//         ListNode* prev = dummy;
//         ListNode* root = head;
//         int cnt = 1;

//         // Step 2: Advance to the starting point
//         while (root) {
//             if (cnt == left) {
//                 break;
//             }
//             prev = root;
//             root = root->next;
//             cnt++;
//         }      

//         // Step 3: Run the localized in-place reversal loop
//         ListNode* root2 = root;
//         ListNode* prev2 = nullptr; // Initialize to nullptr so the sublist tail is clean
        
//         while (root2 && cnt <= right) {
//             ListNode* newroot = root2->next;
//             root2->next = prev2;
//             prev2 = root2;
//             root2 = newroot;
//             cnt++;
//         }

//         // Step 4: Reconnect the broken segments securely
//         prev->next = prev2; // Link node before sublist to new sublist head
//         root->next = root2; // Link original sublist start to remaining tail

//         // Step 5: Save the true head before deleting the dummy node
//         ListNode* actual_head = dummy->next;
//         delete dummy; 
        
//         return actual_head;

//     }
// };
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: if the list is empty or no reversal is needed
        if (!head || left == right) return head;

        // 1. Create a dummy node to cleanly handle the 'left == 1' edge case
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        // 2. Advance 'prev' until it sits exactly one node BEFORE the 'left' position
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }

        // 3. 'curr' is the first node of our sublist. It will eventually become the tail of this sublist.
        ListNode* curr = prev->next;

        // 4. Perform an in-place link adjustment (right - left) times
        for (int i = 0; i < right - left; ++i) {
            ListNode* forward = curr->next; // Temporarily isolate the node to shift
            
            curr->next = forward->next;     // Cut 'forward' out of its current position
            forward->next = prev->next;     // Place 'forward' at the beginning of the sublist
            prev->next = forward;           // Link 'prev' to the newly shifted front node
        }

        // 5. Secure the true head, free memory, and return
        ListNode* actual_head = dummy->next;
        delete dummy; 
        return actual_head;
    }
};
