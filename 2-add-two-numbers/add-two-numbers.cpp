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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0, sum = 0;
        ListNode* deln = new ListNode(-1);
        ListNode* temp = deln;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + c;
            c = sum / 10;
            l1->val = sum % 10;
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            sum = l1->val + c;
            c = sum / 10;
            l1->val = sum % 10;
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            sum = l2->val + c;
            c = sum / 10;
            l2->val = sum % 10;
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
        if (c != 0) {
            ListNode* carry = new ListNode(c);
            temp->next = carry;
        }

        return deln->next;
    }
};