/*
https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
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
    
    vector<int> value;
    int nodes;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        
        if(root -> left) inorder(root -> left);
        value.push_back(root -> val);
        nodes++;
        if(root -> right) inorder(root -> right);
        
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        nodes = 0;
        inorder(root1);
        int p1 = 0, p2 = nodes, br = nodes;
        inorder(root2);
        vector<int> ans;
        while(p1 < br && p2 < nodes)
        {
            if(value[p1] <= value[p2])
            {
                ans.push_back(value[p1]);
                p1++;
            }
            else 
            {
                ans.push_back(value[p2]);
                p2++;
            }
        }
        while(p1 < br)
        {
            ans.push_back(value[p1]);
            p1++;
        }
        while(p2 < nodes)
        {
            ans.push_back(value[p2]);
            p2++;
        }
        
        return ans;
    }
};
