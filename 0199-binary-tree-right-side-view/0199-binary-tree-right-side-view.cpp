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
    void dfs(TreeNode* root,int l, vector<int>& mp)
    {
        if(root==NULL)
        return;
        if(mp.size()==l)
        mp.push_back(root->val);
        dfs(root->right,l+1,mp);
        dfs(root->left,l+1,mp);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        dfs(root,0,ans);
        return ans;
    }
};
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         queue<TreeNode*> q;
//         vector<int> ans;
//         if(root==NULL) return ans;
//         q.push(root);
//         while(!q.empty())
//         {
//             int n=q.size();
//             int temp;
//             while(n--)
//             {
//                 TreeNode* root=q.front();
//                 q.pop();
//                 temp=root->val;
//                 if(root->left!=NULL)
//                 q.push(root->left);
//                 if(root->right!=NULL)
//                 q.push(root->right);
//             }
//             ans.push_back(temp);
//         }
//         return ans;
    
//     }
// };