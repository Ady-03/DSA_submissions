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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }
        if (count < n) return head;
        if (count == n) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        ListNode* curr = head;
        int reached = count - n - 1;
        count = 0;
        while (curr->next != NULL) {
            
            if (count == reached) {
                ListNode* del = curr->next;
                curr->next = curr->next->next;
                delete del;
                break;
            }
            curr = curr->next;
            count++;
        }
        return head;
    }
};
