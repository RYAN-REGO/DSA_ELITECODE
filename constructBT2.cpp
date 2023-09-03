class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         if (inorder.size() != postorder.size())
            return NULL;
        map<int,int> inMap;
        for (int i=0;i<inorder.size();++i)
            inMap[inorder[i]] = i;
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, 
                              postorder.size()-1,inMap);
    }
    TreeNode* buildTreePostIn(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, 
                                     map<int,int> &inMap){
        if (postStart>postEnd || inStart>inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inMap[postorder[postEnd]];
        TreeNode* root->left = buildTreePostIn(inorder, inStart, inRoot-1, postorder, postStart, postStart+inRoot-inStart-1, inMap);
        TreeNode* root->inRootght = buildTreePostIn(inorder,inRoot+1, inEnd, postorder, postStart+inRoot-inStart, postEnd-1, inMap);
        
        return root;
    }
};