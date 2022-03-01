/*
https://leetcode.com/problems/binary-search-tree-iterator/
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
class BSTIterator {
public:
    
    vector<int> backup;
    int pos;
    void inorder(TreeNode* root)
    {
        if(!root) return;
        if(root -> left) {inorder(root -> left);}
        backup.push_back(root -> val);
        if(root -> right) {inorder(root -> right);}
    }
        
    BSTIterator(TreeNode* root) {
        inorder(root);
        pos = 0;
    }
    
    int next() {
        return backup[pos++];
    }
    
    bool hasNext() {
        return pos < backup.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
