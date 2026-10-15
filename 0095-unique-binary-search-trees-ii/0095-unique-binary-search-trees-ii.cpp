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
    void f(int i,int n,vector<TreeNode*>&ans){
          if(i>n){
            ans.push_back(NULL);
            return;
          }
          for(int s = i;s<=n;s++){
                vector<TreeNode*>left;
                vector<TreeNode*>right;
                f(i,s-1,left);
                f(s+1,n,right);
                for(auto l : left){
                    for(auto r : right){
                        TreeNode*root = new TreeNode(s);
                        root ->left = l;
                        root->right = r;
                        ans.push_back(root);
                    }
                }
          }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>ans;
        TreeNode * temp;
        f(1,n,ans);
        return ans;
    }
};