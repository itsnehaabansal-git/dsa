/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root ==  NULL){
            return "";
        }
        string s = "";
     queue<TreeNode*>q;
     q.push(root);
     while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr == NULL){
            s.append("null,");
        }
        else{
            s.append(to_string(curr->val)+",");
        }
        if(curr != NULL){
            q.push(curr->left);
            q.push(curr->right);
        }
     }
     return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if( data == ""){
            return NULL;
        }
       stringstream str(data);
       string s;
       queue<TreeNode*>q;
       getline(str,s,',');
       TreeNode* root = new TreeNode(stoi(s));
       q.push(root);
       while(!q.empty()){
           TreeNode* curr = q.front();
           q.pop();
           getline(str,s,',');
           if(s != "null"){
            curr->left = new TreeNode(stoi(s));
            q.push(curr->left);
           }
           getline(str,s,',');
           if(s != "null"){
            curr->right = new TreeNode(stoi(s));
            q.push(curr->right);
           }




       }
       return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));