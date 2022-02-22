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


// TC : O(N) 
// SC : O(N)
TreeNode* prev = NULL;
void flatten(TreeNode* root) {
    
    if(!root) return;
    
    flatten(root->right);
    flatten(root->left);
    
    root->right = prev;
    root->left = NULL;
    prev = root;
    
}


// TC : O(N)
// SC : O(N)
void flatten(TreeNode* root){

    if(!root) return;

    stack<TreeNode*> st;
    st.push(root);
    
    while(!st.empty()){

        TreeNode* curr = st.top();
        st.pop();

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);

        if(!st.empty())
            curr->right = st.top();
        
        curr->left = NULL;
    }

}


// TC : O(N)
// SC : O(1)
void flatten(TreeNode* root) {
        
    if(!root) return;
    
    TreeNode* curr = root;
    while(curr!=NULL){
        
        if(curr->left){
            TreeNode*prev = curr->left;
            while(prev->right)
                prev = prev->right;
            
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
        
    }
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