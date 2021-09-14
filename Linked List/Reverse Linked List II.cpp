/*
https://leetcode.com/problems/reverse-linked-list-ii/
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
    
    ListNode *rn;
    
    ListNode *rev(ListNode* head, int r)
    {
        if(r == 0)
        {
            rn = head -> next;
            return head;
        }
        
        ListNode* newNode = rev(head -> next, --r);
        head -> next ->next = head;
        return newNode;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right || !head || !head -> next)
        {
            return head;
        }
        
        ListNode *lp, *lTmp, *rTmp;
        lp = NULL;
        rn = NULL;
        lTmp = head;
        right-=left;
        
        while(--left)
        {
            lp = lTmp;
            lTmp = lTmp -> next;
        }
        // cout << lTmp -> val << " " << right;
        rTmp = rev(lTmp, right);
        
        if(lp) 
        {
            lp -> next = rTmp;
        }
        else
        {
            head = rTmp;
        }
        
        lTmp -> next = rn;
        
        return head;
    }
};