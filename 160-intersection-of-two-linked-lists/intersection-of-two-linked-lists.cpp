/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int CA = 0, CB = 0, cc;
        ListNode *ta = headA, *tb = headB;
        while(ta!=nullptr) ta = ta->next, CA++;
        while(tb!=nullptr) tb = tb->next, CB++;
        cc = CA - CB;
        ta = headA, tb = headB;
        while(cc < 0) tb = tb->next, cc++;
        while(cc > 0) ta = ta->next, cc--;

        cc = CA >= CB ? CB : CA;
        while(cc > 0){
            if(ta == tb && ta!=nullptr)return ta;
            else{
                cc--;
                ta = ta->next;
                tb = tb->next;
            }
        }

        return NULL;
    }
};