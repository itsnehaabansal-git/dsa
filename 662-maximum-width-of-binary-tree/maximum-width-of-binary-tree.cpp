/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        queue<pair<TreeNode*, long long >> q;
        long long ans = 0;
        q.push({root,0});
        while (!q.empty()) {
            long long mmin = q.front().second;
            long long s = q.size();
            long long first, last;
            for (int i = 0; i < s; i++) {
                long long curind = q.front().second - mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) {
                    first = curind;
                }
                if (i == s - 1) {
                    last = curind;
                }

                if (node->left) {
                    q.push({node->left, 2 *curind + 1});
                }
                if (node->right) {
                    q.push({node->right, 2 * curind + 2});
                }
              
            }
            ans = max(ans, last - first +1);
        }
        return ans;}
    };