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
    void solve(TreeNode* root ,int level , int vertical , map<int, map<int,multiset<int>>>&nodes){
if(root == NULL){
    return;
}
 nodes[vertical][level].insert(root->val);
 solve(root->left,level+1,vertical-1,nodes);
 solve(root->right,level+1,vertical+1,nodes);

    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>nodes;
        solve(root,0,0,nodes);
        vector<vector<int>>ans;
        for(auto vertical:nodes){
            vector<int>temp;
            for(auto level : vertical.second ){
                for(auto value : level.second ){
                    temp.push_back(value);
                }
               
            }
             ans.push_back(temp);
        }

        return ans;
    }
};