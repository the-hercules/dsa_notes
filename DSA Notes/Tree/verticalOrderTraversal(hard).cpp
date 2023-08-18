#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
   public:
    vector<vector<int>> verticalTraversal(TreeNode *root) {
        queue<pair<TreeNode *, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            TreeNode *temp = q.front().first;
            auto temp1 = q.front();
            // x vertical // y level
            int x = temp1.second.first;
            int y = temp1.second.second;
            q.pop();
            if (temp->left) {
                q.push({temp->left, {x - 1, y + 1}});
            }
            if (temp->right) {
                q.push({temp->right, {x + 1, y + 1}});
            }
            mp[x][y].insert(temp->val);
        }
        vector<vector<int>> ans;
        for (auto i : mp) {
            vector<int> innerVector;
            for (auto j : i.second) {
                innerVector.insert(innerVector.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(innerVector);
        }
        return ans;
    }
};