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
    ListNode* removeNodes(ListNode* head) {
        ListNode* ptr = head ;
        stack<int>st;
        while(ptr!=NULL){
            st.push(ptr->val);
            ptr=ptr->next;
        }

        vector<int>ans;
        int maxi = INT_MIN;
        while(!st.empty()){
            if(st.top()>=maxi){
                maxi = st.top();
                ans.push_back(maxi);
            }
            st.pop();
        }

        int n = ans.size();
        ListNode* headr = nullptr;
        ListNode* tail = nullptr;

        for(int i=n-1;i>=0;i--) {
            ListNode* newNode = new ListNode(ans[i]);

            if(headr == nullptr) {
                headr = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        return headr;
    }
};