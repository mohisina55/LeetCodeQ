/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Solution 1. BF, O(n^2)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValid(root->left, root->val, true) || !isValid(root->right, root->val, false)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
    
    bool isValid(TreeNode* root, int bound, bool isLeft){
        return !root || (isLeft ? root->val < bound : root->val > bound ) && isValid(root->left, bound, isLeft) && isValid(root->right, bound, isLeft);
    }
};

// Solution 2. D & C, O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
    
    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode){
        if(!root) return true;
        if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val) return false;
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
};

// Solution 3. Iterative. O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode* pre = NULL;
        while(root || !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if(pre && root->val <= pre->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};
