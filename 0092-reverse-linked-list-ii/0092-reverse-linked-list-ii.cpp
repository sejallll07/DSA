
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left == right) return head;

        ListNode* ptr = head;
        int cnt = 1;

        ListNode* prev = nullptr;

        while(cnt != left){
            prev = ptr;
            ptr = ptr->next;
            cnt++;
        }

        // Save original head
        ListNode* originalHead = head;

        // If left == 1, new sublist starts from head
        if(prev != nullptr){
            prev->next = NULL;
        }

        head = ptr;

        while(cnt != right){
            ptr = ptr->next;
            cnt++;
        }

        ListNode* last = ptr->next;
        ptr->next = NULL;

        head = reverseList(head);

        if(prev != nullptr){
            prev->next = head;
        }
        else{
            originalHead = head;
        }

        ListNode* temp = head;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = last;

        return originalHead;
    }

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};