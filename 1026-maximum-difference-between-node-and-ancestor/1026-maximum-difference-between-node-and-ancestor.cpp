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
    int ans;
    pair<int,int> helper(TreeNode*root)
    {
        if(root==NULL)
        return {-1e9,1e9};

        pair<int,int>left=helper(root->left);
        pair<int,int> right=helper(root->right);
        int mx=max(left.first,right.first);
        int mn=min(left.second,right.second);
        if(mn!=1e9) ans=max(ans,abs(mn-root->val));
        if(mx!=-1e9) ans=max(ans,abs(mx-root->val));
        return { max(mx,root->val),min(mn,root->val)}; 

    }
    int maxAncestorDiff(TreeNode* root) {
        ans=0;
        helper(root);
        return ans;
    }
};