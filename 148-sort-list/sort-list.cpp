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
    ListNode* findmid(ListNode* head){
        ListNode* s = head;
        ListNode* f = head->next;
        while(f != nullptr && f->next != nullptr){
            s = s->next;
            f = f->next->next;
        }
        return s;
    }
    ListNode* mergeList(ListNode* list1, ListNode* list2){
        ListNode* deln = new ListNode(-1);
        ListNode* temp = deln;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        if(list1) temp->next = list1;
        else temp->next = list2;

        return deln->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *mid = findmid(head);
        ListNode *right = mid->next;
        ListNode *left = head;
        mid->next = NULL;
        
        left = sortList(left);
        right = sortList(right);
        return mergeList(left, right);
    }
};