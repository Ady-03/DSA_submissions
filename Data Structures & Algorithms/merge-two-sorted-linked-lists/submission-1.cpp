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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val >= list2->val) {
                ListNode* curr = new ListNode(list2->val);
                temp->next = curr;
                list2=list2->next;
                temp=temp->next;
            }
            else{
                ListNode* curr = new ListNode(list1->val);
                temp->next = curr;
                list1=list1->next;
                temp=temp->next;
            }
        }
        while (list1 != NULL) {
            ListNode* curr = new ListNode(list1->val);
            list1=list1->next;
            temp->next=curr;
            temp=temp->next;
        }
        while (list2 != NULL) {
            ListNode* curr = new ListNode(list2->val);
            list2=list2->next;
            temp->next=curr;
            temp=temp->next;
        }
        return ans->next;
    }
};
