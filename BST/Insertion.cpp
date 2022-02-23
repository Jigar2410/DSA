#include<bits/stdc++.h>
using namespace std;

struct TreeNode{

    int val;
    TreeNode* left;
    TreeNode* right;
    int smallest;
    int largest;
    int size;

    TreeNode(int data){

        val = data;
        left = NULL;
        right = NULL;
        smallest = INT_MAX;
        largest = INT_MIN;
        size = 0;
    }
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    
    if(!root) return new TreeNode(val);
    
    TreeNode* curr = root;
    
    while(curr){
        
        if(val < curr->val){
            if(curr->left) curr = curr->left;
            else{
                curr->left = new TreeNode(val);
                break;
            }
        }
        else{
            if(curr->right) curr = curr->right;
            else{ 
                curr->right = new TreeNode(val);
                break;
            }
        }
    }
    
    return root;
}

int main(){

    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(15);
    root->right = new TreeNode(40);
    root->left->left = new TreeNode(14);
    root->left->left->right = new TreeNode(17);
    root->left->right = new TreeNode(18);
    root->left->right->left = new TreeNode(16);
    root->left->right->right = new TreeNode(19);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(60);
    root->right->right->left = new TreeNode(50);
    //root->right->right->right = new TreeNode(14);

    cout<<largestBSTSubtree(root)<<endl;
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