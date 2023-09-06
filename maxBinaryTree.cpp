class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructHelper(nums, 0, nums.size()-1);
    }
    TreeNode* constructHelper(vector<int>& nums, int start, int end)
    {
        if(start > end) return nullptr;

        int max_index = start;
        //i <= end
        for(int i = start; i <= end; i++)
        {
            if(nums[i] > nums[max_index])
            {
                max_index = i;
            }
        }

        TreeNode* node = new TreeNode(nums[max_index]);
        node->left = constructHelper(nums, start, max_index-1);
        node->right = constructHelper(nums, max_index+1, end);

        return node;
    }
};