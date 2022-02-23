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

 void recoverTree(TreeNode* root) {
    
    TreeNode* first=NULL,* middle = NULL,* last = NULL,* prev = NULL,*curr = root;
    
    while(curr){
        
        if(curr->left == NULL){
            
            if(prev!=NULL&& prev->val > curr->val){
                    
                if(!first) first = prev, middle = curr;
                else last = curr;
            }

            prev = curr;
            curr = curr->right;
        }
        else{
            
            TreeNode* prev2  = curr->left;
            while(prev2->right && prev2->right!=curr)
                prev2 = prev2->right;
            
            if(prev2->right == NULL) prev2->right = curr, curr = curr->left;
            else{
                prev2->right= NULL;
                
                if(prev!=NULL&& prev->val > curr->val){
                    
                    if(!first) first = prev, middle = curr;
                    else last = curr;
                }

                prev = curr;
                curr = curr->right;
            }
        }
    }
    
    if(first && last){
        swap(first->val,last->val);
    }
    else if(first && middle)
        swap(first->val,middle->val);
    
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
