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
    TreeNode*helper(vector<int>& inorder,int i1,int j1, vector<int>& postorder,int i2,int j2,map<int,int> &mp){
        if(i1 > j1){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[j2]);
        int k = mp[postorder[j2]];
        root->left = helper(inorder, i1, k-1, postorder, i2, i2 + (k - i1) - 1, mp);
        root->right = helper(inorder, k+1, j1, postorder, i2 + (k - i1), j2 - 1, mp);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};