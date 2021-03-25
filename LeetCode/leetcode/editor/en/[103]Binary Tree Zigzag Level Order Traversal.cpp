//Given a binary tree, return the zigzag level order traversal of its nodes' val
//ues. (ie, from left to right, then right to left for the next level and alternat
//e between). 
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
//return its zigzag level order traversal as: 
// 
//[
//  [3],
//  [20,9],
//  [15,7]
//]
// 
// Related Topics Stack Tree Breadth-first Search 
// 👍 2936 👎 120


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> tempV;
        deque<pair<TreeNode *,int>> s;
        vector<pair<TreeNode*,int>> vectorNode;
        s.emplace_back(root,0);
        int floor=0;
        while (!s.empty()||!vectorNode.empty()) {
            if (floor!=s.front().second){
                vector<int> tempNode;
                if(floor%2==0){
                    for(int i=0;i<vectorNode.size();i++){
                        tempNode.push_back(vectorNode[i].first->val);
                    }
                }else{
                    for(int i=vectorNode.size()-1;i>=0;i--){
                        tempNode.push_back(vectorNode[i].first->val);
                    }
                }
                res.push_back(tempNode);
                vectorNode.clear();
                floor=s.front().second;
            }
            if(s.empty())continue;
            TreeNode *tempNode = s.front().first;
            vectorNode.emplace_back(tempNode,floor);
            if (tempNode->left)s.emplace_back(tempNode->left,s.front().second+1);
            if (tempNode->right)s.emplace_back(tempNode->right,s.front().second+1);
            s.pop_front();
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
