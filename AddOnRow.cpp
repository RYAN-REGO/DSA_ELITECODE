class Solution {
public:
//solved in two tries completely by self
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return nullptr;
        if(depth == 1)
        {
            TreeNode* nodeAdd = new TreeNode(val);
            nodeAdd->left = root;
            return nodeAdd;
        }
        return helper(root, val, depth, 1);
    }
    TreeNode* helper(TreeNode* root, int val, int depth, int travel)
    {
        if(travel == depth-1)
        {
            TreeNode* leftAdd = new TreeNode(val);
            TreeNode* leftChild = root->left;
            root->left = leftAdd;
            leftAdd->left = leftChild;

            TreeNode* rightAdd = new TreeNode(val);
            TreeNode* rightChild = root->right;
            root->right = rightAdd;
            rightAdd->right = rightChild;
        }
        if(root->left) helper(root->left, val, depth, travel+1);
        if(root->right) helper(root->right, val, depth, travel+1);
        return root;
    }
};