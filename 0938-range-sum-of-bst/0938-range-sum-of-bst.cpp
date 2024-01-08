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
    void inorder(TreeNode* root, vector<int> &ds, int low, int high)
    {
        if(root == NULL)
            return;
        inorder(root->left, ds, low , high);
        if(root->val >= low && root->val <= high)
            ds.push_back(root->val);
        inorder(root->right, ds, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ds;
        int sum = 0;
        inorder(root, ds, low, high);
        for(int i=0; i<ds.size();i++)
        {
            sum += ds[i];
        }
        return sum;
    }
};