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
    ListNode* reverse(ListNode* head){
        if(head->next == NULL || head == NULL) return head;
        ListNode* n = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return n;
    }

    ListNode* findkth(ListNode* temp, int k){
        k--; 

    // Decrement K until it reaches
    // the desired position
        while(temp != NULL && k > 0){
        // Decrement k as temp progresses
            k--; 
        
        // Move to the next node
        temp = temp -> next; 
    }
    
    // Return the Kth node
    return temp; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head, *nextn = head, *pren = NULL, *kthn = head;
        while(temp){
            kthn = findkth(temp, k);
            if(kthn == NULL){
                if(pren) pren->next = temp;
                break;
            }
            nextn = kthn->next;
            kthn->next = NULL;
            kthn = reverse(temp);
            if(temp == head) head = kthn;
            else pren->next = kthn;

            pren = temp;
            temp = nextn;
        }
        return head;
    }
};