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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* oc = head;
        ListNode* eh = head->next, *ec = head->next;
        while(ec != nullptr && oc != nullptr){
            if(ec->next == nullptr){
                oc->next = eh;
                break;
            }else{
                oc->next = ec->next;
                oc = oc->next;
            }
            if(oc->next == nullptr){
                ec->next = NULL;
                oc->next = eh;
                break;
            }else{
                ec->next = oc->next;
                ec = ec->next;
            }
        }

        return head;
    }
};