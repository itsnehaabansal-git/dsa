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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int ps, int pe,int is, int ie, unordered_map<int, int>&mp){
        if ((ps>pe) or (is>ie)){
            return NULL;
        }
        int rootval = postorder[pe];
        TreeNode* root = new TreeNode(rootval);
     int inroot = mp[rootval];
     int leftnodes = inroot - is;
     root->left =solve(inorder,postorder,ps,ps+leftnodes-1,is,inroot-1,mp );
     root->right = solve(inorder,postorder,ps+ leftnodes,pe-1,inroot+1, ie,mp);
     return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>mp;
        for(int i =0; i< inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        return solve(inorder,postorder,0,postorder.size()-1 , 0 , inorder.size()-1,mp);
    }
};