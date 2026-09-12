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
    TreeNode* helper(string arr, int& i,int d)
    {
        int n=arr.size();
        if(i==n) return nullptr;
        
        int j=i;
        int nd=0;
        while(j<n &&arr[j]=='-') {
            nd++; 
            j++;
        }

        if(nd<=d) return nullptr;

        i=j;

        TreeNode* curr= new TreeNode();
        int vl=0;
        while(i<n && arr[i]!='-')
        {
           vl= vl*10+(arr[i]-'0');
           i++;
        }
        curr->val=vl;

        curr->left=helper(arr,i,nd); // we need updated i so will pass i with &
        curr->right=helper(arr,i,nd);
        return curr;

    }
    TreeNode* recoverFromPreorder(string traversal) {
        int i=0;
        return helper(traversal,i,-1);
    }
};