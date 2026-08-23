// class Solution {
// public:
//     vector<TreeNode*> solve(int l, int r) {
//         if (l > r) return {nullptr};

//         vector<TreeNode*> ans;
//         for (int root = l; root <= r; root++) {
//             vector<TreeNode*> leftTrees = solve(l, root - 1);
//             vector<TreeNode*> rightTrees = solve(root + 1, r);

//             for (TreeNode* left : leftTrees) {
//                 for (TreeNode* right : rightTrees) {
//                     TreeNode* node = new TreeNode(root);

//                     node->left = left;
//                     node->right = right;

//                     ans.push_back(node);
//                 }
//             }
//         }

//         return ans;
//     }

//     vector<TreeNode*> generateTrees(int n) {
//         return solve(1, n);
//     }
// };
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
private:
    map<pair<int,int>, vector<TreeNode*>> memoMap;

    vector<TreeNode*> helper(int start, int end) {
        if(start > end) {
            return {nullptr};
        }

        if(memoMap.find({start, end}) != memoMap.end())
            return memoMap[{start, end}];
        
        vector<TreeNode*> currTrees;
        for(int currNode=start;  currNode<=end; currNode++) {
            vector<TreeNode*> leftSubTrees = helper(start, currNode-1);
            vector<TreeNode*> rightSubTrees = helper(currNode+1, end);

            for(int i=0; i<leftSubTrees.size(); i++) {
                for(int j=0; j<rightSubTrees.size(); j++) {
                    TreeNode* root = new TreeNode(currNode, leftSubTrees[i], rightSubTrees[j]);
                    currTrees.push_back(root);
                }
            }
        }

        return memoMap[{start,end}] = currTrees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
};