class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        TreeNode* original = root;
        TreeNode* left = NULL;
        TreeNode* right = NULL;
        TreeNode* parent = NULL;

        while(root)
        {
            if(root->val == key)
                break;

            parent = root;

            if(root->val < key)
                root = root->right;
            else
                root = root->left;
        }

        if(root == NULL) return original;

        left = root->left;
        right = root->right;

        // deleting root
        if(parent == NULL)
        {
            if(!right) return left;

            TreeNode* p = right;
            while(p->left)
                p = p->left;

            p->left = left;
            return right;
        }

        if(parent->left && parent->left->val == key)
        {
            if(!right)
                parent->left = left;
            else
            {
                parent->left = right;

                TreeNode* p = right;
                while(p->left)
                    p = p->left;

                p->left = left;
            }
        }
        else
        {
            if(!left)
                parent->right = right;
            else
            {
                parent->right = left;

                TreeNode* p = left;
                while(p->right)
                    p = p->right;

                p->right = right;
            }
        }

        return original;
    }
};