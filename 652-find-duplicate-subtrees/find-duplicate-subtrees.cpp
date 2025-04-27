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
    string helper(TreeNode* root, unordered_map<string ,int> &mp,vector<TreeNode*> &result){
        if(root==NULL){
            return "null";
        }
        string s = to_string(root->val) + ","+ helper(root->left,mp,result) +","+ helper(root->right,mp,result);
        if(mp[s]==1){
            result.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string ,int> mp;

        vector<TreeNode*> result;

        helper(root,mp,result);

        return result;
    }
};