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
    vector<int> inorderTraversal(TreeNode* root) {
        //left root right
        vector<int>v;
        if(root == NULL){
            return v;
        }
       vector<int>left =  inorderTraversal(root->left);
       for(int x:left){
        v.push_back(x);
       }
        v.push_back(root->val);
       vector<int>right = inorderTraversal(root->right);
       for(int x :right){
        v.push_back(x);
       }
       return v;
    }
};