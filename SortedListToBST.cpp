
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      if(head == NULL) return nullptr;
      
      return constructTree(head, nullptr);  
    }
    TreeNode* constructTree(ListNode* head, ListNode* tail)
    {
        if(head == tail) return nullptr;
        if(head->next == tail)
        {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }
        ListNode* mid = head, *temp = head;
        while(temp != tail && temp->next != tail)
        {
            mid = mid->next;
            temp = temp->next->next;
        }
        TreeNode *root = new TreeNode(mid->val);
        root->left = constructTree(head, mid);
        root->right = constructTree(mid->next, tail);
        return root;
    }
};