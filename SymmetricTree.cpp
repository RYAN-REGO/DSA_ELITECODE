class Solution{
    public : 

    bool isSymmetricHelp(TreeNode* left, TreeNode *right)
    {
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL)  return false;
        if(left->val != right->val) return false;
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if(root == NULL) return false;
        return isSymmetricHelp(root->left, root->right);

    }
};