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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(int x : nums) st.insert(x);
        ListNode* temph = new ListNode();
        temph->next = head;
        ListNode* temp = temph;
        while(temp->next){
            if(st.count(temp->next->val)){
                temp->next = temp->next->next;  
            }
            else temp = temp->next; 
        }

        return temph->next;
    }
};