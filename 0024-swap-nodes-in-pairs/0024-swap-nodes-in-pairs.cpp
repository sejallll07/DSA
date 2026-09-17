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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr = head;
        if(head==NULL || head->next==NULL)return head; 
        ListNode* ptr2 = head->next;
        ListNode* temp = new ListNode( );
        temp->next = ptr;
        while(ptr!=nullptr && ptr2!=nullptr){
            ptr->next = ptr2->next;
            ptr2->next = ptr;
            temp->next = ptr2;
            if(ptr==head) head=ptr2;

            temp = ptr;
            ptr = ptr->next;
            if(ptr)ptr2 = ptr->next;


        }

        return head;
    }
};