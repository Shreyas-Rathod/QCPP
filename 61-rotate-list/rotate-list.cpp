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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *temp = head;
        while(temp) len++, temp = temp->next;
        if(len <= 1) return head;

        ListNode *st = head, *end = head;
        len = len>k ? k : k%len;
        while(len--) end = end->next;
        while(end->next != nullptr){
            st = st->next;
            end = end->next;
        }
        end->next = head;
        temp = st->next;
        st->next = NULL;
        return temp;
    }
};