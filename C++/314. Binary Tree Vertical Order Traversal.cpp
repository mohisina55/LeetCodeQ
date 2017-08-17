/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>>m;
        vector<vector<int>>res;
        if(!root) return res;

        deque<pair<int, TreeNode*>>cur;
        deque<pair<int, TreeNode*>>sub;
        
        int offset = 0;
        
        cur.push_back(make_pair(offset, root));
        
        while(!cur.empty()){
            pair<int, TreeNode*>* p = &cur.front();
            cur.pop_front();
            m[p->first].push_back(p->second->val);
            if(p->second->left) sub.push_back(make_pair(p->first - 1, p->second->left));
            if(p->second->right) sub.push_back(make_pair(p->first + 1, p->second->right));
            if(cur.empty()) swap(cur, sub);
        }
        
        for(auto x: m) res.push_back(x.second);
        
        return res;
    }
};
