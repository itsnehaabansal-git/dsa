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
    bool check(TreeNode* left , TreeNode* right){
    if(left == NULL and right == NULL){
        return true;
    }
    if(left == NULL or right == NULL){
        return false;
    }
    if(left->val == right->val){
       bool c= check(left->left,right->right);
       bool d = check(left->right,right->left);
       if(c== true and d == true){
        return true;
       }
       else{
        return false;
       }
    }
    return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
      return check(root->left, root->right);
    }
};