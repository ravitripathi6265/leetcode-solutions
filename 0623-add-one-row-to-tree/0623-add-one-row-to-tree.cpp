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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *rt = new TreeNode(val);
            rt->left = root;
            return rt;
        }
         queue<pair<TreeNode*,int>>q;
         q.push({root,1});
         while(!q.empty()){
            TreeNode* Node = q.front().first;
            int d = q.front().second;
            q.pop();
            if(d == depth-1){
                TreeNode * left = Node->left;
                TreeNode * right = Node->right;
                TreeNode * temp = new TreeNode(val);
                TreeNode *temp2 = new TreeNode(val);
                Node ->left = temp;
                Node->right = temp2;
                temp->left = left;
                temp2->right = right;
                
            }
            else{
                if(Node->left){
                      q.push({Node->left,d+1});
                }
                if(Node->right){
                  q.push({Node->right,d+1});
                }
            }

         }
         return root;
    }
};