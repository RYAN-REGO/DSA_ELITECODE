
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        dfsHeight(root, diameter);
        return diameter;
    }
    private : 
        int dfsHeight(TreeNode *root, int &diameter)
        {
            if(!root)
            {
                return 0;
            }
            int lh = dfsHeight(root->left, diameter);
            int rh = dfsHeight(root->right, diameter);
            diameter = max(diameter, lh + rh);
            return 1 + max(lh, rh);
        }
};