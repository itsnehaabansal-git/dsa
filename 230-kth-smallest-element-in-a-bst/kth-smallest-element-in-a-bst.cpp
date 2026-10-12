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
    void inorder1(TreeNode* root,vector<int>&inorder){
           if(root == NULL){
             return;
        }
         inorder1(root->left,inorder);
        inorder.push_back(root->val);
        inorder1(root->right,inorder);
     
       
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
     inorder1(root,inorder);
        return inorder[k-1];

    }
};