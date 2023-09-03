
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int res = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            res++;
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode *root = q.front();
                q.pop();

                if(root->left != NULL) q.push(root->left);
                if(root->right != NULL) q.push(root->right);
            }
        }
        return res;
    }
};