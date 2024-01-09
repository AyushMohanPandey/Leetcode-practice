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
    void inorder(TreeNode* root, int val, TreeNode* node)
    {
        
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL)
            return root;
        TreeNode* node = new TreeNode();
         if(val<root->val){
            //search in left 
            node=searchBST(root->left,val);
        } else if(val>root->val){
            //search in right
            node=searchBST(root->right,val);
        } else {
            //required node
            node=root;
        }
        return node;
    }
};