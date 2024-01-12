#include<iostream>

using namespace std;
class TreeNode{
   public :
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
      data = val;
      left = NULL;
      right = NULL;
    }
};
bool check(TreeNode* root1, TreeNode* root2){
      if(!root1 || !root2)
         return root1 == root2;
      if(root1->data != root2->data)
         return false;
    return  check(root1->left,root2->right) && check(root1->right,root2->left);
}
bool isSymmetric(TreeNode *root){
     if(!root)
        return true;
    return check(root->left,root->right);  
}
int main(){
   TreeNode* root = NULL;
   root = new TreeNode (5);
   root->left = new TreeNode (10);
   root->right = new TreeNode (10);
   root->left->left = new TreeNode (30);
   root->left->right = new TreeNode (40);
   root->right->left = new TreeNode (40);
   root->right->right = new TreeNode (30);
   isSymmetric(root) ? cout << "Yes": cout << "NO";
    
}
/*
       5
     /   \
   10     10
  /  \   /  \
30   40 40   30

*/
