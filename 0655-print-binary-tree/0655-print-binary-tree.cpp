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
     int f(TreeNode *root){
        if(root == NULL)return 0;
        return 1 + max(f(root->left),f(root->right));
     }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = f(root) -1;
        int m = h+1;
        int n = pow(2,h+1)-1;
        vector<vector<string>>ans(m,vector<string>(n,""));
        queue<pair<TreeNode*,pair<int,int>>>q;
        
        int r = m;
        int c = n;
        q.push({root,{0,(n-1)/2}});
        ans[0][(n-1)/2] =to_string(root->val);

        while(!q.empty()){
            TreeNode * node = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            if(node->left){
                int ncol =  (c-pow(2,h-r-1));
                ans[r+1][ncol] = to_string(node->left->val);
                q.push({node->left,{r+1,ncol}});
            }
             if(node->right){
                int ncol =  (c+pow(2,h-r-1));
                ans[r+1][ncol] = to_string(node->right->val);
                q.push({node->right,{r+1,ncol}});
            }

        }
        return ans;
    }
};