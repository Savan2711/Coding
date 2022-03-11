/*
https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head || !head -> next) return head;
        
        int ln  = 0;
        ListNode *p1 = head, *p2;
        
        while(p1)
        {
            ln++;
            p1 = p1 -> next;
        }
        
        k = k % ln;
        if(k == 0) return head;
        p1 = head;
        
        while(k--)
        {
            p1 = p1 -> next;
        }
        
        p2 = head;
        while(p1 -> next)
        {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        ListNode *ans = p2 -> next;
        p2 -> next = NULL;
        p1 -> next = head;
        
        return ans;
        
    }
};
