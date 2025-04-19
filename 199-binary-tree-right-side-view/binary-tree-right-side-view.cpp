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

    //LEVEL ORDER 

    // vector<int> rightSideView(TreeNode* root) {
    //     if(root ==  NULL){
    //         return  {};
    //     }
    //     queue <TreeNode*> que;
    //     que.push(root);
    //     vector<int> result;
    //     while(!que.empty()){
    //         int n = que.size();
    //         TreeNode*node= NULL;
    //         while(n--){
    //             node=que.front();
    //             que.pop();
    //             if(node->left != NULL){
    //                 que.push(node->left);
    //             }
    //             if(node->right !=NULL){
    //                 que.push(node->right);
    //             }
    //         }
    //         result.push_back(node->val);
    //     }
    //     return result;
    // }

    //DFS
    void preorder(TreeNode* root,int level , vector<int> &result){
        if(!root){
            return;
        }
        if(result.size()<level){
            result.push_back(root->val);
        }
        preorder(root->right,level+1,result);
        preorder(root->left,level+1,result);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        preorder(root,1, result);
        return result;
    }
};