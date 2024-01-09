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
    void inorder(TreeNode* root, vector<int> &ds)
    {
        if(root == NULL)
            return;
        inorder(root->left, ds);
        if(root->left == NULL && root->right == NULL)
        {
            ds.push_back(root->val);
        }
        inorder(root->right, ds);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ds1;
        vector<int> ds2;
        inorder(root1, ds1);
        inorder(root2, ds2);
        if(ds1.size() != ds2.size())
            return false;
        for(int i=0;i<ds1.size();i++)
        {
            if(ds1[i] != ds2[i])
                return false;
        }
        return true;
    }
};