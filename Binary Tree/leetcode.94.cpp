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
#include<bits/stdc++.h>
using namespace std;
struct treenode{
    int val;
    treenode* right;
    treenode* left;
};
class Solution {
public:
    void dfs(treenode* root);
    vector<int> inorderTraversal(treenode* root);
    vector<int>res;
};
void Solution::dfs(treenode* root){
    if(!root)return;
    dfs(root->left);
    res.push_back(root->val);
    dfs(root->right);
}
vector<int>Solution:: inorderTraversal(treenode* root){
    dfs(root);
    return res;
}
int main (){
    treenode* root=new treenode{1,nullptr,nullptr};//有几个节点new几次
    treenode* node2=new treenode{2,nullptr,nullptr};
    treenode* node3=new treenode{3,nullptr,nullptr};
    root ->right=node2;
    node2->left=node3;
    Solution sol;
    vector<int>ans=sol.inorderTraversal(root);
    for(int x:ans){
        cout<<x<<" ";
    }
    return 0;
}