
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int j = 0;
        while(!q.empty())
        {
            j++;
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(!node->left && !node->right) return j;
            }
        }
        return -1;
    }
};