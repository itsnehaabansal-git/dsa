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
    unordered_map<int,int>mp;
TreeNode* solve(vector<int>&preorder,vector<int>&inorder,int prestart, int preend, int instart, int inend ){

    if(prestart > preend or instart > inend){
        return NULL;
    }

  int rootval = preorder[prestart];
  TreeNode* root = new TreeNode(rootval);
  int rootindex = mp[rootval];
  int leftnodes = rootindex - instart;
  root->left = solve(preorder,inorder,prestart+1,prestart + leftnodes ,instart , rootindex-1);
  root->right = solve(preorder, inorder , prestart + leftnodes +1 , preend, rootindex+1, inend);
return root;

}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0 ; i< inorder.size(); i++){
          mp[inorder[i]]= i;
        }
        return solve(preorder,inorder,0,preorder.size()-1 , 0, inorder.size()-1);
    }
};