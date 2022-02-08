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

bool isLeaf(TreeNode* root){

    return (!root->left && !root->right);
}

void addLeftBoundary(TreeNode* root, vector<int>& res){

    TreeNode* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addRightBoundary(TreeNode* root, vector<int>& res){

    TreeNode* curr = root->right;
    vector<int> temp;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->val);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}

void addLeaves(TreeNode* root, vector<int>& res){

    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }

    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);
}

vector<int> BoundaryTraversal(TreeNode* root){

    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->val);
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);
    return res;
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
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(16);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(11);
    root->right->right->left->right = new TreeNode(13);
    root->right->right->right = new TreeNode(12);

    vector<int> v = BoundaryTraversal(root);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";        
    }  
    /*
                    
                    1
                  /   \ 
                 /     \
                /       \ 
               2         3
             /  \      /   \    
            4    5    6     7
           /    /  \   \   / \
         17    8    9  16 11  12
             / \   /        \
           10  14 15        13
 
    */
    return 0;
}