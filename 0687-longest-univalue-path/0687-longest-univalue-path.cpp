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
//     int ans;
//     int height(TreeNode* root)
//     {
//         if(!root)
//         return 0;

//         int lh=height(root->left);
//         int rh=height(root->right);

//         if(root->left && root->left->val==root->val && root->right && root->right->val==root->val)
//         {
//             ans=max(ans,lh+1+rh);
//             return 1+max(lh,rh);
//         }
//         else if( root->left && root->left->val==root->val)
//         {
//             ans=max(ans,lh+1);
//             return 1+lh;
//         }
//         else if(root->right && root->right->val==root->val)
//         {
//             ans=max(ans,rh+1);
//             return 1+rh;
//         }
//         else
//         {
//             return 1;
//         }
//     }
//     int longestUnivaluePath(TreeNode* root) {
//         ans=1;
//         height(root);
//         return ans-1;
//     }
// };

class Solution {
public:
    int ans;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        // 1. Recursively get the longest univalue paths from left and right children
        int leftPath = dfs(root->left);
        int rightPath = dfs(root->right);

        // Variables to track the valid univalue path extending from the current root
        int arrowLeft = 0, arrowRight = 0;

        // 2. If left child exists and matches root's value, extend the path
        if (root->left && root->left->val == root->val) {
            arrowLeft = leftPath + 1;
        }

        // 3. If right child exists and matches root's value, extend the path
        if (root->right && root->right->val == root->val) {
            arrowRight = rightPath + 1;
        }

        // 4. Update the global maximum path (combining left and right extensions)
        ans = max(ans, arrowLeft + arrowRight);

        // 5. Return the single longest branch to the parent node
        return max(arrowLeft, arrowRight);
    }

    int longestUnivaluePath(TreeNode* root) {
        ans = 0; // The problem measures paths by edges, so start at 0
        dfs(root);
        return ans;
    }
};
