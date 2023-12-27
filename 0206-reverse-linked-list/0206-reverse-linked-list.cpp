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
// class Solution {
// public:
//     ListNode* rCall(ListNode* head)
//     {
//         if(head->next == NULL)
//         {
//             return head;
//         }
//         ListNode* newhead = rCall(head->next);
//         head->next->next=head;
//         head->next=NULL;
//         return newhead;
//     }
//     ListNode* reverseList(ListNode* head) {
//         if(head == NULL)
//             return NULL;
//         return rCall(head);
//     }
// };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        stack<int> st;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};












