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
    void reorderList(ListNode* head) {
        if(head==NULL) return;
        if(head->next==NULL)return;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        vector<ListNode*>alter;
        while(second!=nullptr){
            alter.push_back(second);
            second = second->next;
        }

        reverse(alter.begin(),alter.end());

        ListNode* temp = head;
        for(int i=0;i<alter.size();i++){
            ListNode* ptr = alter[i];
            ptr->next = temp->next;
            temp->next = ptr;
            temp = ptr->next;

        }

        

    }
};