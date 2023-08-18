//naive way with reverse operation 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> outerVector;
        if(root==nullptr){
            return outerVector;
        }
        queue<TreeNode*> q;
        stack<TreeNode*> st;
        q.push(root);
        bool rtl=false;
        while(!q.empty()){
            int queueSize=q.size();
            vector<int> innerVector;
            for(int i=0;i<queueSize;i++){
                cout<<q.size()<<endl;
                TreeNode* temp=q.front();
                q.pop();
                innerVector.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            } 
            if(rtl){
                reverse(innerVector.begin(),innerVector.end());
                outerVector.push_back(innerVector);
            }
            else{
            outerVector.push_back(innerVector);
            }
            rtl=rtl?false:true;
        }
        return outerVector;
    }
    
};


//improvement is using a way to store the node's value in a vector
//in the correct order only, look below


vector < vector < int >> zigzagLevelOrder(Node * root) {
  vector < vector < int >> result;
  if (root == NULL) {
    return result;
  }

  queue < Node * > nodesQueue;
  nodesQueue.push(root);
  bool leftToRight = true;

  while (!nodesQueue.empty()) {
    int size = nodesQueue.size();
    vector < int > row(size);
    for (int i = 0; i < size; i++) {
      Node * node = nodesQueue.front();
      nodesQueue.pop();

      // find position to fill node's value, according to the
      //leftToRight value, if from right to left then fill vector 
      //FROM BEHIND



      int index = (leftToRight) ? i : (size - 1 - i);







      row[index] = node -> val;
      if (node -> left) {
        nodesQueue.push(node -> left);
      }
      if (node -> right) {
        nodesQueue.push(node -> right);
      }
    }
    // after this level
    leftToRight = !leftToRight;
    result.push_back(row);
  }
  return result;
}