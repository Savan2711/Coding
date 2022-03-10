/*
https://leetcode.com/problems/add-two-numbers/
*/

/* Iterative solution */
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int prev = 0;
        ListNode* ans, *cur, *prevNd;
        ans = new ListNode();
        cur = ans;
        while(l1 && l2)
        {
            cur -> val = (l1 -> val + l2 -> val + prev) % 10;//new ListNode((l1 -> val + l2 -> val + prev) % 10);
            prev = (l1 -> val + l2 -> val + prev) / 10;
            cur -> next = new ListNode();
            prevNd = cur;
            cur = cur -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1)
        {
            cur -> val = (l1 -> val + prev) % 10;//ListNode((l1 -> val + prev) % 10);
            prev = (l1 -> val + prev) / 10;
            cur -> next = new ListNode();
            prevNd = cur;
            cur = cur -> next;
            l1 = l1 -> next;
        }
        while(l2)
        {
            cur -> val = ((l2 -> val) + prev) % 10;//ListNode((l2 -> val + prev) % 10);
            prev = ((l2 -> val) + prev) / 10;
            cur -> next = new ListNode();
            prevNd = cur;
            cur = cur -> next;
            l2 = l2 -> next;
        }
        if(prev)
        {
            cur -> val = prev;
            cur -> next = NULL;
        }
        else
        {
            prevNd -> next = NULL;
            cur = NULL;
        }
        return ans;
    }
};

/* Recursive solution */
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
    
    int carry = 0;
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(!(l1 -> next)  && !(l2 -> next))
        {
            return new ListNode((l1 -> val + l2 -> val + carry) % 10, (l1 -> val + l2 -> val + carry) / 10 > 0 ? new ListNode((l1 -> val + l2 -> val + carry) / 10) : NULL);
        }
        
        int v = (l1 -> val + l2 -> val + carry) % 10;
        carry = (l1 -> val + l2 -> val + carry) / 10;
        return new ListNode(v, addTwoNumbers(l1 -> next ? l1 -> next : new ListNode(), l2 -> next ? l2 -> next : new ListNode()));
        
        
    }
};
