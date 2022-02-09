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


void verticalRecursive(TreeNode* root, int vertical, int level, map<int,map<int,vector<int>>>&mp){

    if(!root) return;

    mp[vertical][level].push_back(root->val);
    verticalRecursive(root->left,vertical-1,level+1,mp);
    verticalRecursive(root->right,vertical+1,level+1,mp);

}

void verticalRecursiveV2(TreeNode* root, int vertical,int level,map<int,map<int,multiset<int>>>&mp){

    if(!root) return;

    mp[vertical][level].insert(root->val);
    verticalRecursiveV2(root->left,vertical-1,level+1,mp);
    verticalRecursiveV2(root->right,vertical+1,level+1,mp);
}

// If 2 or more Tree Nodes shares the same vertical level then the one with earlier 
// occurence in the pre-order traversal of tree comes first in the output.
vector<vector<int>> verticalOrderTraversal(TreeNode* root){

    vector<vector<int>> ans;
    if(!root) return ans;
    map<int,vector<int>> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front().first;
            int vertical = q.front().second;
            q.pop();

            mp[vertical].push_back(curr->val);

            if(curr->left) q.push({curr->left,vertical-1});
            if(curr->right) q.push({curr->right,vertical+1});
        }
    }

    for(auto x : mp){
        ans.push_back(x.second);
    }

    return ans;
}


// There may be multiple nodes in the same row and same column. 
// In such a case, sort these nodes by their values.
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    map<int,map<int,multiset<int>>> mp;
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            mp[vertical][level].insert(curr->val);

            if(curr->left) q.push({curr->left,{vertical-1,level+1}});
            if(curr->right) q.push({curr->right,{vertical+1,level+1}});
        }
    }
    for(auto x : mp){
        vector<int> level;
        for(auto y : x.second){
            level.insert(level.end(),y.second.begin(),y.second.end());
        }
        ans.push_back(level);
    }

    return ans;
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

    vector<vector<int>> v = verticalOrderTraversal(root);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;      
    }  

    cout<<endl<<endl; 

    vector<vector<int>> v1 = verticalTraversal(root);
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v1[i].size();j++){
            cout<<v1[i][j]<<" ";
        }
        cout<<endl;      
    }  

    cout<<endl<<endl; 

    vector<vector<int>> ans;
    map<int,map<int,vector<int>>> mp;
    verticalRecursive(root,0,0,mp);
    for(auto x : mp){
        vector<int> level;
        for(auto y : x.second){
            level.insert(level.end(),y.second.begin(),y.second.end());
        }
        ans.push_back(level);
    }

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;      
    }

    cout<<endl<<endl; 

    vector<vector<int>> ans1;
    map<int,map<int,multiset<int>>> mp1;
    verticalRecursiveV2(root,0,0,mp1);
    for(auto x : mp1){
        vector<int> level;
        for(auto y : x.second){
            level.insert(level.end(),y.second.begin(),y.second.end());
        }
        ans1.push_back(level);
    }
    for(int i=0;i<ans1.size();i++){
        for(int j=0;j<ans1[i].size();j++){
            cout<<ans1[i][j]<<" ";
        }
        cout<<endl;      
    }    
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
