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
    vector<int> rv(TreeNode* root , int level, vector<int>&v){
if(root == NULL){
    return v;
};
if(level == v.size()){
v.push_back(root->val);
};
rv(root->right,level+1,v);
rv(root->left,level+1,v);
return v;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int>v;
       return rv(root,0,v);
      
    };
};