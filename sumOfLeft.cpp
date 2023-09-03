
class Solution {
public:
    void sumFunc(TreeNode* root, int& sum, int flag)
    {
        if(!root) return;
        if(!root->left && !root->right && flag == 1)
        {
            sum += root->val;
        }
        flag = 1;
        sumFunc(root->left, sum, flag);
        flag = 0;
        sumFunc(root->right, sum, flag);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0; //for no nodes
        /*if(root && !root->left && !root->right) return root->val;//for one node only*/
        int sum = 0;
        int flag = 0;
        sumFunc(root, sum, flag);
        return sum;
    }
};