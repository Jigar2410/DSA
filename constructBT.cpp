#include<bits/stdc++.h>
using namespace std;

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){

        val = data;
        left = NULL;
        right = NULL;
    }
};


TreeNode* construct(vector<int>&preorder,int&preIndex, vector<int>&inorder, int inStart, int inEnd, unordered_map<int,int>&inMap){

    if(preIndex >= preorder.size() || inStart > inEnd) return NULL;

    int inRoot = inMap[preorder[preIndex]];
    TreeNode* root = new TreeNode(preorder[preIndex++]);

    root->left = construct(preorder,preIndex,inorder,inStart,inRoot-1,inMap);
    root->right = construct(preorder,preIndex,inorder,inRoot+1,inEnd,inMap);

    return root;
}

TreeNode* buildTree(vector<int>&preorder, vector<int>&inorder){

    unordered_map<int,int> inMap;

    for(int i=0;i<inorder.size();i++) 
        inMap[inorder[i]] = i;

    int preIndex = 0;
    return construct(preorder,preIndex,inorder,0,inorder.size()-1,inMap);
}

TreeNode* construct(vector<int>&postorder,int& postIndex, vector<int>&inorder, int inStart, int inEnd, unordered_map<int,int>&inMap){

    if(postIndex < 0  || inStart > inEnd) return NULL;

    int inRoot = inMap[postorder[postIndex]];
    TreeNode* root = new TreeNode(postorder[postIndex--]);

    root->right = construct(postorder,postIndex,inorder,inRoot+1,inEnd,inMap);
    root->left = construct(postorder,postIndex,inorder,inStart,inRoot-1,inMap);
    
    return root;
}

TreeNode* buildTree(vector<int>&inorder, vector<int>&postorder){

    unordered_map<int,int> inMap;

    for(int i=0;i<inorder.size();i++) 
        inMap[inorder[i]] = i;

    int postIndex = postorder.size()-1;
    return construct(postorder,postIndex,inorder,0,inorder.size()-1,inMap);
}

int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(17);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->left->left = new TreeNode(10);
    root->left->right->left->right = new TreeNode(14);
    root->left->right->right = new TreeNode(9);
    root->left->right->right->left = new TreeNode(15);
    root->right->left = new TreeNode(5);
    root->right->left->right = new TreeNode(16);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(11);
    root->right->right->left->right = new TreeNode(13);
    root->right->right->right = new TreeNode(12);


    /*
                    
                    1
                  /   \ 
                 /     \
                /       \ 
               2         3
             /  \      /   \    
            4    6    5     7
           /    /  \   \   / \
         17    8    9  16 11  12
             / \   /        \
           10  14 15        13
 
    */
    return 0;
}