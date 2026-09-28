/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   void markparent(unordered_map<TreeNode*,TreeNode*>&parent_tracker,TreeNode* root,TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent_tracker[curr->left]= curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_tracker[curr->right]= curr;
                q.push(curr->right);
            }
        }

    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_tracker;
        markparent(parent_tracker,root,target);
         unordered_map<TreeNode*,bool>visited;
         queue<TreeNode*>q1;
         q1.push(target);
         visited[target]=true;
         int currl =0;
         while(!q1.empty()){
            int s= q1.size();
             if (currl == k){
                break;
            }
            currl++;
            for(int i =0; i<s; i++){
                 TreeNode* curr = q1.front();
            q1.pop();
            
        
               if(curr->left && !visited[curr->left]){
                q1.push(curr->left);
                visited[curr->left]=true;
               }
               if(curr->right && !visited[curr->right ]){
                q1.push(curr->right);
                visited[curr->right]=true;
               }
               if(parent_tracker[curr] and !visited[parent_tracker[curr]]){
                q1.push(parent_tracker[curr]);
                visited[parent_tracker[curr]]= true;
               }
            }
         }
       vector<int>ans;
       while(!q1.empty()){
         
        TreeNode* v = q1.front();
        q1.pop();
        ans.push_back(v->val);
       }

return ans;
    }
};