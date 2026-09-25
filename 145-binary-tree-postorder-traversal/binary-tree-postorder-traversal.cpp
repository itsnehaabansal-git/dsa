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
    vector<int> postorderTraversal(TreeNode* root) {
        //left right root 
        vector<int>v;
        if(root == NULL){
            return v;
        }

        vector<int>left = postorderTraversal(root->left);
        for(int x:left){
            v.push_back(x);
        }
        vector<int>right = postorderTraversal(root->right);
        for(int x:right){
            v.push_back(x);
        }
        v.push_back(root->val);
        return v;
    }
};