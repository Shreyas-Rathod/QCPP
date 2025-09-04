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
    ListNode* rev(ListNode *head){
        if(head == NULL || head->next == NULL) return head;
        ListNode *n = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return n;
    }
    ListNode* findnext(ListNode *head, int k){
        while(head != NULL && k-- > 0) head = head->next;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head, *nexthead = NULL, *prev, *kthnode;
        while(temp){
            kthnode = findnext(temp, k-1);
            if(kthnode == NULL){
                if(prev) prev->next = temp;
                break;
            }
            
            nexthead = kthnode->next;
            kthnode->next = NULL;
            rev(temp);

            if(temp == head) head = kthnode;
            else{
                prev->next = kthnode;
            }

            prev = temp;
            temp = nexthead;
        }
        return head;
    }
};