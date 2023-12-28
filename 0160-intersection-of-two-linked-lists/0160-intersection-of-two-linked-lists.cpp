/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//******* hashmap********    TC = O(m+n) , SC = O(m)

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         map<ListNode*,int> mp;
//         ListNode* temp1 = headA;
//         ListNode* temp2 = headB;
//         while(temp1!=NULL)
//         {
//             mp[temp1] = 1;
//             temp1 = temp1->next;
//         }
//         while(temp2!=NULL)
//         {
//             if(mp.find(temp2)!=mp.end())
//                 return temp2;
//             temp2 = temp2->next;
//         }
//         return NULL;
//     }
// };

//***** tortoise and hare *****    TC = O(m+n) , SC = O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        if (temp1 == NULL || temp2 == NULL) return NULL;
        while(temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
            if(temp1 == temp2)
                return temp1;
            if(temp1 == NULL)
            {
                temp1 = headB;
            }
            if(temp2 == NULL)
            {
                temp2 = headA;
            }
        }
        return temp1;
    }
};

//***** Brute force *****   TC = O(m*n) , SC = O(1)

// class Solution {
// public:
// 	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
// 		ListNode *temp;
// 		while(headA != NULL){
// 			temp = headB;
// 			while(temp != NULL){
// 				if(headA == temp){
// 					return headA;
// 				}
// 				temp = temp -> next;
// 			}
// 			headA = headA -> next;
// 		}
// 		return NULL;
// 	}
// };





