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
    ListNode* reverseList(ListNode* head) {
        ListNode* Next = NULL;      // To temporarily store the next node
        ListNode* pre = NULL;       // Previous node, initially NULL
        ListNode* current = head;   // Current node pointer

        // Traverse the linked list
        while(current != NULL){
            Next = current->next;   // Store next node
            current->next = pre;    // Reverse the current node's pointer
            pre = current;          // Move previous to current
            current = Next;         // Move current to next node
        }

        return pre;  // New head of the reversed linked list
    }
};
