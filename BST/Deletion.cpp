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

TreeNode* findLastRight(TreeNode* root){

        while(root->right)
            root = root->right;
        
        return root;
}

TreeNode* helper(TreeNode* root) {
    
    if (root->left == NULL) 
    {
        return root->right;
    } 
    else if (root->right == NULL)
    {
        return root->left;
    } 
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

TreeNode* deleteNodeV2(TreeNode* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == key) {
        return helper(root);
    }
    TreeNode *dummy = root;
    while (root != NULL) {
        if (root->val > key) {
            if (root->left != NULL && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right != NULL && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}

TreeNode* deleteNodeV1(TreeNode* root, int key) {
    
    TreeNode* curr = root,*parent = NULL;
    while(curr){
        if(curr->val == key) break;
        else if(key < curr->val) parent = curr, curr = curr->left;
        else parent = curr, curr = curr->right;
    }
    
    if(!curr) return root;
    
    if(parent){
        if(curr == parent->left){
            if(curr->left){
              parent->left = curr->left;
              TreeNode* prev = findLastRight(curr->left);
              prev->right = curr->right;
              
            }
            else{
                parent->left = curr->right;
            }
        }
        else{
            if(curr->left){
                parent->right = curr->left;
                TreeNode* prev = findLastRight(curr->left);
                prev->right = curr->right;
            }
            else{
                parent->right = curr->right;
            }
        }
    }
    else if(curr==root){
        
        if(curr->left){
            root = curr->left;
            TreeNode* prev = findLastRight(curr->left);
            prev->right = curr->right;
        }
        else{
            root = curr->right;
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