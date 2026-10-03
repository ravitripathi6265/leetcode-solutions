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
    void preo(TreeNode*root ,int &ans,int left,int high){
        if(root == NULL)return;
        if(root->val>=left  && root->val <=high){
            ans+= root->val;
        }
        preo(root->left,ans,left,high);
        preo(root->right,ans,left,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        preo(root,ans,low,high);
        return ans;
    }
};