#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
class Solution {
   public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node* root) {
        queue<pair<Node*, pair<int, int>>> q;
        map<int, pair<int, int>> mp;
        q.push({root, {0, 0}});
        while (!q.empty()) {
            auto i = q.front();
            q.pop();
            Node* temp = i.first;
            int vertical = i.second.first;
            int horizontal = i.second.second;
            //IMPORTANT
           // .INSERT() FUNCTION DOES NOT UPDATE THE VALUE IF THE KEY ALREADY EXISTS
            mp.insert({vertical, {horizontal, temp->data}});
            if (temp->left) {
                q.push({temp->left, {vertical - 1, horizontal + 1}});
            }
            if (temp->right) {
                q.push({temp->right, {vertical + 1, horizontal + 1}});
            }
        }
        vector<int> ans;
        for (auto i : mp) {
            ans.push_back(i.second.second);
        }
        return ans;
    }
};