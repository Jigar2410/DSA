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


// TreeNode* searchBST(TreeNode* root,int val){

//     while(root && root->val!=val)
//         root = (root->val < val)?root->right : root->left;

//     return root;
// }


TreeNode* searchBST(TreeNode* root,int val){

    if(!root || root->val == val)
        return root;

    return (root->val < val)?searchBST(root->right,val):searchBST(root->left,val);
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

    cout<<searchBST(root,4)->val<<endl;
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
