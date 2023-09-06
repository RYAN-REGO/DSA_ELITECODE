
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* root, int curr)
    {
        if(!root) return 0;

        curr = curr * 10 + root->val;

        if(!root->left && !root->right) return curr;

        return dfs(root->left, curr) + dfs(root->right, curr);
    }
};