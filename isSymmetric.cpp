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

bool symUtil(TreeNode* p, TreeNode* q){
        
    if(!p || !q){
        return (p==q);
    }
    
    return (p->val == q->val)
        && symUtil(p->left,q->right)
        && symUtil(p->right,q->left);
}
    
bool isSymmetric(TreeNode* root) {
        
    if(!root) return false;
    return symUtil(root->left,root->right);
}


bool isSymmetricV2(TreeNode* root) {

    if(!root) return false;
    queue<pair<TreeNode*,TreeNode*>> q;
    q.push({root->left,root->right});
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr1 = q.front().first;
            TreeNode* curr2 = q.front().second;
            q.pop();
            
            if(!curr1 || !curr2){
                if(curr1!=curr2) return false;
                continue;
            }  
            
            if(curr1->val!= curr2->val) return false;
            
            TreeNode* left1 = NULL,*right1 = NULL,*left2 = NULL,*right2 = NULL;
            if(curr1->left) left1 = curr1->left;
            if(curr1->right) right1 = curr1->right;
            if(curr2->left) left2 = curr2->left;
            if(curr2->right) right2 = curr2->right;
            
            q.push({left1,right2});
            q.push({left2,right1});
        }
    }

    return true;
}
int main(){

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(17);
    root->left->right = new TreeNode(6);
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

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->right->right = new TreeNode(3);

    cout<<isSymmetric(root)<<endl;
    cout<<isSymmetric(root1)<<endl;

    cout<<isSymmetricV2(root)<<endl;
    cout<<isSymmetricV2(root1)<<endl;
    
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
