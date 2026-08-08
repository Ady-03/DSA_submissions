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
    void reorderList(ListNode* head) {
        // slow & fast algo
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = NULL;

        ListNode* prev = NULL;

        while (second != NULL) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        ListNode* h1 = head;
        ListNode* h2 = prev;
        while (h2) {
            ListNode* t1 = h1->next;
            ListNode* t2 = h2->next;

            h1->next = h2;
            h2->next = t1;

            h1 = t1;
            h2 = t2;
        }
    }
};