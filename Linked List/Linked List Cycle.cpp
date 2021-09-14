/*
https://leetcode.com/problems/linked-list-cycle/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *first = head, *second = head;
        
        
        while(first && first -> next)
        {
            first = first -> next -> next;
            second = second -> next;
            
            if(first == second) break;
        }
        
        if(!first || !first -> next) return false;
        
        return true;
        
    }
};