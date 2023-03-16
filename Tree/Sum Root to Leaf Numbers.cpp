/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
private:
    int ans;
public:

    void preorder(TreeNode* root, int cur)
    {
        if(!root) return;
        if(!(root -> left) && !(root -> right)) ans += cur*10 + root -> val;
        if(root -> left) preorder(root -> left, (cur*10 + root -> val));
        if(root -> right) preorder(root -> right, (cur*10 + root -> val));
    }

    int sumNumbers(TreeNode* root) {
        ans = 0;
        preorder(root, 0);
        return ans;
    }
};
