/*
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long total, ans;
    
    void preorder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        
        total += root -> val;
        
        if(root -> left) preorder(root -> left);
        if(root -> right) preorder(root -> right);
        
    }
    
    long maxSumProduct(TreeNode* root)
    {
        if(!root) return 0;
        
        long l = 0, r = 0;
        if(root -> left) l = maxSumProduct(root -> left);
        if(root -> right) r = maxSumProduct(root -> right);
        
        if(ans < (total - l - r - root -> val) * (l + r + root -> val))
        {
            ans = ((total - l - r - root -> val) * (l + r + root -> val) );
        }
        
        return l + r + root -> val;
        
    }
    
    int maxProduct(TreeNode* root) {
        
        total = 0;
        ans = INT_MIN;
        
        preorder(root);
        
        maxSumProduct(root);
        
        return ans % 1000000007;
    
    }
};