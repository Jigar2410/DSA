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

int succ = -1;
void successor(TreeNode* root,int val){

    if(!root) return;

    if(val < root->val){
        succ = root->val;
        successor(root->left,val);
    }
    else{
        successor(root->right,val);
    }
}

int pred = -1;
void predecessor(TreeNode* root,int val){

    if(!root) return;

    if(val > root->val){
        pred = root->val;
        predecessor(root->right,val);
    }
    else{
        predecessor(root->left,val);
    }
}

int main(){

    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(12);
    root->right->right->left = new TreeNode(11);
    root->right->right->right = new TreeNode(14);

    successor(root,9);
    cout<<succ<<endl;
    predecessor(root,9);
    cout<<pred<<endl;
    /*
                    
                   8
                  / \ 
                 6   9
                /  \  \       
               4    7  12  
              /        / \
             1        11  14                           
 
    */
    return 0;
}