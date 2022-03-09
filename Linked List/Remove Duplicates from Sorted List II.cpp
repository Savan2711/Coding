/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
*/

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
    ListNode* deleteDuplicates(ListNode* A) {
        
        if(A == NULL || A -> next == NULL)
        {return A;}

        ListNode *head = new ListNode(0), *temp = A, *cur;
        cur = head;

        while(temp)
        {
            int flag = 0;
            while(temp -> next && ((temp -> val) == (temp -> next -> val)))
            {
                temp = temp -> next;
                flag = 1;
            }

            if(!flag)
            {
                cur -> next = temp;
                cur = cur -> next;
            }
            temp = temp -> next;

        }
        
        cur -> next = NULL;
        return head -> next;

    }
};
