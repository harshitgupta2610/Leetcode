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
 bool solve(TreeNode* root, int targetSum,int sum){
        if(!root){
            return false;
        }
        sum+=root->val;
        if(!root->left && !root->right){
            if(sum==targetSum){
                return true;
            }
            return false;
        }
        bool left = solve(root->left,targetSum,sum);
        bool right = solve(root->right,targetSum,sum);
        return left||right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum =0;
        bool res = solve(root,targetSum,sum);
        return res;
    }
class Solution {
public:
    vector<vector<int>> result;
    void solve(TreeNode* root, int targetSum,int sum,vector<int> &temp){
        if(!root){
            return ;
        }
        sum+=root->val;
        temp.push_back(root->val);
        if(!root->left&& !root->right){
            if(sum==targetSum){
                result.push_back(temp);
            }
        }
        solve(root->left,targetSum,sum,temp);
        solve(root->right,targetSum,sum,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum =0;
        vector<int> temp;
        solve(root,targetSum,sum,temp);
        return result;
    }
};