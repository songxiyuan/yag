//Given a binary tree, check whether it is a mirror of itself (ie, symmetric aro
//und its center). 
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric: 
//
// 
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
// 
//
// But the following [1,2,2,null,3,null,3] is not: 
//
// 
//    1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
// 
//
// Follow up: Solve it both recursively and iteratively. 
// Related Topics Tree Depth-first Search Breadth-first Search 
// 👍 5310 👎 130


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
    bool isSymmetric(TreeNode *root) {
        if(root==nullptr)return true;
        return isSymmetric(root->left,root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)return true;
        if (left == nullptr || right == nullptr || left->val != right->val)return false;
        return isSymmetric(left->left,right->right) && isSymmetric(left->right,right->left);
    }
};
//leetcode submit region end(Prohibit modification and deletion)
