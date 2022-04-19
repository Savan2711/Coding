/*
https://leetcode.com/problems/recover-binary-search-tree/
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
    
    vector<int> trace;
    int i;
    
    void inorder(TreeNode* root)
    {
        if(!root)
        {return;}
        
        if(root -> left) inorder(root -> left);
        trace.push_back(root -> val);
        if(root -> right) inorder(root -> right);

    }
    
    void makeTree(TreeNode* root)
    {
        if(!root)
        {return;}
        
        if(root -> left) makeTree(root -> left);
        root -> val = trace[i++];
        if(root -> right) makeTree(root -> right);

    }
    
    void recoverTree(TreeNode* root) {
        
        inorder(root);
        sort(trace.begin(), trace.end());
        i = 0;
        makeTree(root);
        
    }
};
