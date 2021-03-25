//Given a binary tree, return the level order traversal of its nodes' values. (i
//e, from left to right, level by level). 
//
// 
//For example: 
//Given binary tree [3,9,20,null,null,15,7], 
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
// 
// 
// 
//return its level order traversal as: 
// 
//[
//  [3],
//  [9,20],
//  [15,7]
//]
// 
// Related Topics Tree Breadth-first Search 
// 👍 3966 👎 96


//leetcode submit region begin(Prohibit modification and deletion)
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
    vector <vector<int>> levelOrder(TreeNode *root) {
        vector <vector<int>> res;
        if (root == nullptr)return res;
        queue <pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            pair < TreeNode * , int > temp = q.front();
            q.pop();
            if (res.size() < temp.second) {
                res.push_back(vector<int>());
            }
            res[temp.second - 1].push_back(temp.first->val);
            if (temp.first->left) {
                q.push(make_pair(temp.first->left, temp.second + 1));
            }
            if (temp.first->right) {
                q.push(make_pair(temp.first->right, temp.second + 1));
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
