 void addLeft(Node *root, vector<int> &ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        ans.push_back(root->data);
        addLeft(root->left);
        addLeft(root->right);
    }
    void addLeaf(Node *root, vector<int> &ans) {
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->data);
            addLeaf(root->left);
            addLeaf(root->right);
        }
    }
    void addRight(Node *root, vector<int> &ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        if (root->right) {
            addRight(root->right);
        } else {
            addRight(root->left);
        }
        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root) {
        vector<int> ans;
        // adding root node
        ans.push_back(root->data);
        // adding left boundary
        addLeft(root->left, ans);
    }