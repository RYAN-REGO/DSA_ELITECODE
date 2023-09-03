class Solution {
public:
    vector<int> TopSideView(TreeNode* root) {
        //store final ans
        vector<int> ans;

        if(root == NULL) return ans;
        //to store the top view elements in sorted order
        map<int, int> mpp;
        
        queue<pair<Node*, int>> q;
        q.push(root, q);

        while(!q.empty())
        {
            auto it : q.front();
            q.pop();
            TreeNode *node = it.first;
            int line = it.second;

            if(mpp.find(line) == mpp.end()) {
                mpp[line] = node->val;
            }

            if(node->left != NULL) {
                q.push({node->left, line-1});
            }
            if(node->right != NULL){
                q.push({node->right, line + 1});
            }
        }
        for(auto it : mpp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};