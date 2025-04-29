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
    int result;
    int find (TreeNode* root,int &count){
        if(root==NULL){
            return 0;
        }
        count++;
        int l = find(root->left,count);
        int r = find(root->right,count);
        return l+r+root->val;
    }
    void solve(TreeNode* root){
        if(root==NULL){
            return;
        }
        int count =0;
        int total = find(root,count);
        if((total)/count==root->val){
            result++;
        }
        solve(root->left);
        solve(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        result =0;
        solve(root);
        return result;
    }
};