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

class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

NodeValue largestBSTSubtreeHelper(TreeNode* root) {
    // An empty tree is a BST of size 0.
    if (!root) {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }
    
    // Get values from left and right subtree of current tree.
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);
    
    // Current node is greater than max in left AND smaller than min in right, it is a BST.
    if (left.maxNode < root->val && root->val < right.minNode) {
        // It is a BST.
        return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                        left.maxSize + right.maxSize + 1);
    }
    
    // Otherwise, return [-inf, inf] so that parent can't be valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBSTSubtree(TreeNode* root) {
    return largestBSTSubtreeHelper(root).maxSize;
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