stack<TreeNode*> st;
        TreeNode *node = root;

        vector<int> inorder;

        while(1)
        {
            //travel left till left subtree in not NULL
            if(node != NULL)
            {
                st.push(node);
                node = node->left;
            }
            //if left subtree is null pop it and print it then check for right subtree
            else
            {
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;