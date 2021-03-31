#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <queue>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
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

class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,1));
        while(!q.empty()){
            pair<TreeNode*,int> temp=q.front();
            q.pop();
            if(res.size()<temp.second){
                res.push_back(vector<int>());
            }
            res[temp.second-1].push_back(temp.first->val);
            if (temp.first->left){
                q.push(make_pair(temp.first->left,temp.second+1));
            }
            if (temp.first->right){
                q.push(make_pair(temp.first->right,temp.second+1));
            }
        }
        return res;
    }
};

int main1() {
    TreeNode a0(0);
    TreeNode a1(1);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    TreeNode a5(5);
    TreeNode a6(6);
    a0.left=&a1;
    a0.right=&a2;
    a2.left=&a3;
    a2.right=&a4;
    a3.left=&a5;
    a3.right=&a6;
    Solution s;
    vector<vector<int>> res=s.zigzagLevelOrder(&a0);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int countPrimes(int n) {
    vector<bool> sieve=vector<bool>(n,false);
    int count=0;
    for(int i=2;i<n;i++){
        if(sieve[i])continue;
        count++;
        for(int j=2;j*i<n;j++)sieve[j*i]=true;
    }
    return count;
}

int main() {
    cout<<countPrimes(10)<<endl;
    TreeNode a0(0);
    TreeNode a1(1);
    TreeNode a2(2);
    TreeNode a3(3);
    TreeNode a4(4);
    TreeNode a5(5);
    TreeNode a6(6);
    a0.left=&a1;
    a0.right=&a2;
    a2.left=&a3;
    a2.right=&a4;
    a3.left=&a5;
    a3.right=&a6;
    Solution2 s;
    vector<vector<int>> res=s.levelOrder(&a0);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<"\t";
        }
        cout<<endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}