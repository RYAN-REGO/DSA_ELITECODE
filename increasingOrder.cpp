//very fucked up solution
class Solution {
public:
    queue<int> q;
    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        TreeNode* node = new TreeNode(q.front());
        TreeNode* first = node;
        q.pop();
        while(!q.empty())
        {
            node->right = new TreeNode(q.front());
            q.pop();
            node = node->right;
        }
        return first;
    }
    void inorder(TreeNode *root)
    {
        if(root == NULL) return;
        inorder(root->left);
        q.push(root->val);
        inorder(root->right);
    }
};

//best time complexity
class Solution{
    public : 
          void inorder(TreeNode*& ans, TreeNode* root) {
        if (!root) return;
        inorder(ans, root->left);
        ans->right = new TreeNode(root->val);
        ans = ans->right;
        inorder(ans, root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp;
        TreeNode* ans = new TreeNode();
        temp = ans;
        inorder(ans, root);
        return temp->right;
    }
};