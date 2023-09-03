class Solution{
    public : 
        bool checkTree(root)
        {
            if(root == NULL) return true;
            if(!root->left && !root->right) return true;
            if(root->left->val + root->right->val != root->val) return false;
            
            return checkTree(root->left) && checkTree(root->right);
        }
}