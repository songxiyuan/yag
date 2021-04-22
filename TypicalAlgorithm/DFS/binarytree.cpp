#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

void init(TreeNode *root)
{
    root ->val = 0;
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node1 -> left = node2;
    node1 -> right = node3;
    root -> left = node1;
    TreeNode *node4 = new TreeNode(4);
    root->right=node4;
}

//二叉树的前中后序遍历
void preOrderTraverse(TreeNode* head){
    if(head == nullptr) 	return ;
    else
    {
        cout << head->val <<endl;
        preOrderTraverse(head -> left);
        preOrderTraverse(head -> right);
    }
}
void inOrderTraverse(TreeNode* head)
{
    if(head == nullptr) return ;
    else
    {
        inOrderTraverse(head -> left);
        cout << head->val <<endl;
        inOrderTraverse(head -> right);
    }
}
void postOrderTraverse(TreeNode* head)
{
    if(head == nullptr) return ;
    else
    {
        postOrderTraverse(head -> left);
        postOrderTraverse(head -> right);
        cout << head->val <<endl;
    }
}

//二叉树层次遍历
void LevelTraverse(TreeNode* root)
{
    if(root == NULL) return ;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty())
    {
        TreeNode* tempNode = que.front();
        que.pop();
        cout <<tempNode->val <<endl;
        if(root->left != NULL) que.push(tempNode->left);
        if(root->right != NULL) que.push(tempNode->right);
    }
    return ;
}

//二叉树K层节点个数
int getKthnum(TreeNode* head, int k)
{
    if(head == nullptr || k < 1) return 0;
    if (k==1)  return 1;
    int left_num = getKthnum(head->left,k-1);
    int right_num = getKthnum(head->right,k-1);
    return left_num + right_num;
}
//叶子节点个数
int GetLeafNodeNum(TreeNode * head)
{
    if(head == nullptr)  return 0;
    if (head->left == nullptr && head->right ==nullptr) return 1;
    int left_num =  GetLeafNodeNum(head->left);
    int right_num = GetLeafNodeNum(head->right);
    return left_num + right_num;
}
//判断是否平衡二叉树
int depth(TreeNode* root)
{
    if(root == nullptr)
        return 0;
    int left_depth = depth(root->left);
    int right_depth =  depth(root->right);
    return max(left_depth, right_depth) + 1;
}
bool isBalanced(TreeNode* root) {
    if(root == nullptr)
        return true;
    int left = depth(root->left);
    int right =  depth(root->right);
    bool flag = abs(left - right) <=1?true:false;
    return flag && isBalanced(root->left) && isBalanced(root->right);
}

//二叉树镜像递归实现
void Mirror(TreeNode *pRoot) {
    if(pRoot==NULL)
    {
        return;
    }
    swap(pRoot->left,pRoot->right);
    Mirror(pRoot->right);
    Mirror(pRoot->left);
}
//二叉树镜像非递归实现
void Mirror2(TreeNode *pRoot) {
    if(pRoot==NULL)
    {
        return;
    }
    queue<TreeNode*>  q;
    q.push(pRoot);
    while(!q.empty())
    {
        TreeNode *per = q.front();
        TreeNode *tmp = per->left;
        per->left = per->right;
        per->right = tmp;
        if(per->right!=NULL)
        {
            q.push(per->right);
        }
        if(per->left!=NULL)
        {
            q.push(per->left);
        }
    }
    q.pop();
}

//二叉树的右视图，这个方法挺好的！
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if(root != nullptr)
    {
        queue<TreeNode*> Queue;
        Queue.push(root);
        while(!Queue.empty())
        {
            res.push_back(Queue.front()->val);
            int size = Queue.size();
            for(int i = 1;i <= size;++i)
            {
                TreeNode *Node = Queue.front();
                Queue.pop();
                if(Node->right != NULL)
                    Queue.push(Node->right);
                if(Node->left != NULL)
                    Queue.push(Node->left);
            }
        }
    }
    for(auto i:res)cout<<i;
    return res;
}
vector<int> rightSideView0(TreeNode* root) {
    vector<int> res;
    if(root != nullptr)
    {
        queue<pair<TreeNode*,int>> Queue;
        Queue.push(make_pair(root,0));
        while(!Queue.empty())
        {
            TreeNode *Node= Queue.front().first;
            int depth=Queue.front().second;
            if(res.size()<=depth)res.push_back(Node->val);
            else res[depth]=Node->val;
            Queue.pop();
            if(Node->left != NULL)
                Queue.push(make_pair(Node->left,depth+1));
            if(Node->right != NULL)
                Queue.push(make_pair(Node->right,depth+1));
        }
    }
    for(auto i:res)cout<<i;
    return res;
}

//先序遍历和中序遍历构造二叉树
TreeNode* buildTree(vector<int> &preOrder,vector<int> &inOrder,int &pre,int inStart,int inEnd){
    if(pre==preOrder.size())return nullptr;
    pre++;
    if(inStart==inEnd){
        return new TreeNode(inOrder[inStart]);
    }
    TreeNode *root=new TreeNode(preOrder[pre]);
    int mid;
    for(mid=inStart;mid<=inEnd;mid++){
        if(inOrder[mid]==preOrder[pre])break;
    }
    root->left=buildTree(preOrder,inOrder,pre,inStart,mid);
    root->right=buildTree(preOrder,inOrder,pre,mid,inEnd);
}
void buildTree(){
    vector<int> preOrder={0,1,2,3,4};
    vector<int> inOrder={2,1,3,0,4};
    int pre=-1;
    TreeNode *root=buildTree(preOrder,inOrder,pre,0,preOrder.size()-1);
    preOrderTraverse(root);
}

//二叉树的最大最小深度
int maxDepth(TreeNode* root) {
    if(root==nullptr)
        return 0;
    else
        return 1+ max(maxDepth(root->left),maxDepth(root->right));
}

//判断是否为二叉搜索树
int findMaxValInBST(TreeNode root,int maxVal) {
    if(root==nullptr)
        return maxVal;

    if(root.val>maxVal)
        maxVal=root.val;

    int leftMax=findMaxValInBST(root.left, maxVal),rightMax=findMaxValInBST(root.right, maxVal);

    return leftMax>rightMax?leftMax:rightMax;
}

int findMinValInBST(TreeNode root,int minVal) {
    if(root==nullptr)
        return minVal;

    if(root.val<minVal)
        minVal=root.val;

    int leftMin=findMinValInBST(root.left, minVal),rightMin=findMinValInBST(root.right, minVal);

    return leftMin<rightMin?leftMin:rightMin;
}
bool isBST(TreeNode* root) {
    if(root==nullptr)
        return true;

    if(root->left==nullptr && root->right==nullptr)
        return true;

    int leftMax=findMaxValInBST(root->left, Integer.MIN_VALUE);
    int rightMin=findMinValInBST(root->right, Integer.MAX_VALUE);
    if(leftMax>=root->val)return false;
    if(rightMin<=root->val)return false;

    if(root->left!=nullptr && root->right==nullptr)
        return root->left->val < root->val && isBST(root->left);
    if(root->left==nullptr && root->right!=nullptr)
        return root->right->val > root->val && isBST(root->right);

    return root->left->val < root->val && root->right->val > root->val && isBST(root->left)  && isBST(root->right);

}

//最低的搜索二叉树共同祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(p==q || p->right==q || p->left==q)
        return p;
    else if(q->left==p || q->right==p)
        return q;

    if(root->val>p->val && root->val>q->val) {
        return lowestCommonAncestor(root->left, p, q);
    }else if (root->val<p->val && root->val<q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }else {
        return root;
    }
}


int main(){
    TreeNode *root;
    init(root);
    buildTree();
    return 0;
}

