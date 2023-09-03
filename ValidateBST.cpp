class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidbst(root, LONG_MIN, LONG_MAX);
    }
    bool isValidbst(TreeNode* root, long minVal, long maxVal)
    {
        if(root == NULL) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return isValidbst(root->left, minVal, root->val) && isValidbst(root->right, root->val, maxVal); 
    }
    
};

