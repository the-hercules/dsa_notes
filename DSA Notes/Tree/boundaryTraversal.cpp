class Solution {
public:
     void addLeft(Node *root, vector<int> &ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        ans.push_back(root->data);
        if(root->left){
        addLeft(root->left,ans);
        }else{
        addLeft(root->right,ans);
        }
    }
    void addLeaf(Node *root, vector<int> &ans) {
        if(root==nullptr){
            return ;
        }
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(root->data);
        }
         addLeaf(root->left,ans);
         addLeaf(root->right,ans);
    }
    void addRight(Node *root, vector<int> &ans) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return;
        }
        //when adding node on right, we first traverse then print
        if (root->right) {
            addRight(root->right,ans);
        } else {
            addRight(root->left,ans);
        }
        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root) {
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        // adding root node
        ans.push_back(root->data);
        // adding left boundary
        addLeft(root->left, ans);
        //adding left leaf
        addLeaf(root->left,ans);
        //adding right leaf;
        addLeaf(root->right,ans);
        //adding right boundary
        addRight(root->right,ans);
    }
};