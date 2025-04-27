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
    long sum =0;
    long maxv =0;
    int find(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int lefts = find(root->left);
        int rights =find(root->right);
        long subtre= root->val + lefts +rights;
        long subtreeremain = sum - subtre;
        maxv = max(maxv ,subtre*subtreeremain );

        return subtre;
    }

    int total (TreeNode* root){
        if(root==NULL){
            return 0 ;
        }
        int leftsub =  total(root->left);
        int rightsub = total (root->right);
        return root->val + leftsub +rightsub;
    }
    int maxProduct(TreeNode* root) {
        total(root);
        maxv=0;
        sum = total(root);
        find(root);
        return maxv%1000000007;
    }
};