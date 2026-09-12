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
//     TreeNode* helper(string arr, int& i,int d)
//     {
//         int n=arr.size();
//         if(i==n) return nullptr;
        
//         int j=i;
//         int nd=0;
//         while(j<n &&arr[j]=='-') {
//             nd++; 
//             j++;
//         }

//         if(nd<=d) return nullptr;

//         i=j;

//         TreeNode* curr= new TreeNode();
//         int vl=0;
//         while(i<n && arr[i]!='-')
//         {
//            vl= vl*10+(arr[i]-'0');
//            i++;
//         }
//         curr->val=vl;

//         curr->left=helper(arr,i,nd); // we need updated i so will pass i with &
//         curr->right=helper(arr,i,nd);
//         return curr;

//     }
//     TreeNode* recoverFromPreorder(string traversal) {
//         int i=0;
//         return helper(traversal,i,-1);
//     }
// };
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st;
        int i = 0, n = traversal.size();
        
        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }
            
            int val = 0;
            while (i < n && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }
            
            TreeNode* node = new TreeNode(val);
            
            while (!st.empty() && st.top().second >= depth) {
                st.pop();
            }
            
            if (!st.empty()) {
                if (!st.top().first->left) {
                    st.top().first->left = node;
                } else {
                    st.top().first->right = node;
                }
            }
            
            st.push({node, depth});
        }
        
        while (st.size() > 1) st.pop();
        return st.top().first;
    }
};