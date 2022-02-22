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

void preorder(TreeNode* root){
    
    if(!root) return;
    
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

vector<int> inorderTraversal(TreeNode* root) {
        
    vector<int> res;
    if(!root) return res;
    TreeNode*curr = root;
    
    while(curr!=NULL){
        
        if(curr->left == NULL){
            res.push_back(curr->val);
            curr = curr->right;
        }
        else{
            
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!=curr)
                prev = prev->right;
            
            if(prev->right==NULL){
                
                prev->right = curr;
                curr = curr->left;
            }
            else{
                res.push_back(curr->val);
                prev->right=NULL;
                curr = curr->right;
            }
        }
    }
    return res;
}

vector<int> preorderTraversal(TreeNode* root) {
        
    vector<int> res;
    if(!root) return res;
    TreeNode*curr = root;
    
    while(curr!=NULL){
        
        if(curr->left == NULL){
            res.push_back(curr->val);
            curr = curr->right;
        }
        else{
            
            TreeNode* prev = curr->left;
            while(prev->right && prev->right!=curr)
                prev = prev->right;
            
            if(prev->right==NULL){
                 res.push_back(curr->val);
                prev->right = curr;
                curr = curr->left;
            }
            else{
               
                prev->right=NULL;
                curr = curr->right;
            }
        }
    }
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
        
    vector<int> res;
    if(!root) return res;
    
    TreeNode* curr = root;
    while(curr!=NULL){
        
        if(curr->right==NULL){
            res.push_back(curr->val);
            curr = curr->left;
        }
        else{
            
            TreeNode* prev = curr->right;
            while(prev->left && prev->left != curr)
                prev = prev->left;
            
            if(prev->left == NULL){
                res.push_back(curr->val);
                prev->left = curr;
                curr = curr->right;
            }
            else{
                
                prev->left = NULL;
                curr = curr->left;
            }
        }
    }
    reverse(res.begin(),res.end());
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