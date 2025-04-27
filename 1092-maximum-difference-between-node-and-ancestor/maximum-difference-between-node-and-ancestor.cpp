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
    int maxd;
    void maxduntil(TreeNode* root,TreeNode* child){
        if(root == NULL||child == NULL){
            return;
        }
        maxd = max(maxd,abs(root->val -  child->val));
        maxduntil(root,child->left);
        maxduntil(root,child->right);
    }
    void findmaxd(TreeNode* root){
        if(root==NULL){
            return ;
        }
        maxduntil(root,root->left);
        maxduntil(root,root->right);
        findmaxd(root->left);
        findmaxd(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxd=-1;
        findmaxd(root);
        return maxd;
    }
};