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
    int count(ListNode* head)
    {
        int c=0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            c++;
            temp = temp->next;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = count(head);
        ListNode* temp = head;
        if(c == n)
            return head->next;
        int k = 1;
        while(temp != NULL)
        {
            if(k == c-n)
            {
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
            k++;
        }
        return head;
    }
};