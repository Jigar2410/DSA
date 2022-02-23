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

int Floor=-1;
void floorBST(TreeNode* root,int val){

    if(!root) return;
    if(root->val == val){
        Floor = val;
        return;
    }

    if(val > root->val){
        Floor = root->val;
        floorBST(root->right,val);
    }
    else{
        floorBST(root->left,val);
    }
}

void floorBST1(TreeNode* root,int val){

    while(root){

        if(root->val == val){
            Floor = val;
            return;
        }

        if(val > root->val){
            Floor=root->val;
            root = root->right;
        }
        else
            root=root->left;
    }
}

int Ceil=-1;
void ceilBST(TreeNode* root,int val){

    if(!root)
        return;
    
    if(root->val==val) {
        Ceil = val;
        return;
    }

    if(val < root->val){
        Ceil = root->val;
        ceilBST(root->left,val);
    }
    else{
        ceilBST(root->right,val);
    }
}

void ceilBST1(TreeNode* root,int val){

    while(root){
        if(root->val == val){
            Ceil = val;
            return;
        }

        if(val < root->val){
            Ceil = root->val;
            root = root->left;
        }
        else
            root = root->right;
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

   ceilBST1(root,5);
   cout<<Ceil<<endl;
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