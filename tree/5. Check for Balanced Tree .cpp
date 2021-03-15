/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Example 1:

Input:
      1
    /
   2
    \
     3 
Output: 0
Explanation: The max difference in height
of left subtree and right subtree is 2,
which is greater than 1. Hence unbalanced
Example 2:

Input:
       10
     /   \
    20   30 
  /   \
 40   60
Output: 1
Explanation: The max difference in height
of left subtree and right subtree is 1.
Hence balanced. 

Expected time complexity: O(N)
Expected auxiliary space: O(h) , where h = height of tree
*/

/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
int max(int a, int b) 
{ 
    return (a >= b) ? a : b; 
} 
  
/* The function Compute the "height"  
of a tree. Height is the number of  
nodes along the longest path from  
the root node down to the farthest leaf node.*/
int height(Node* node) 
{ 
    /* base case tree is empty */
    if (node == NULL) 
        return 0; 
  
    /* If tree is not empty then  
    height = 1 + max of left  
        height and right heights */
    return 1 + max(height(node->left), 
                   height(node->right)); 
} 
  
// This function should return tree if passed  tree 
// is balanced, else false. 
bool isBalanced(Node *root)
{
    //  Your Code here
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */
  
    /* If tree is empty then return true */
    if (root == NULL) 
        return 1; 
  
    /* Get the height of left and right sub trees */
    lh = height(root->left); 
    rh = height(root->right); 
  
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right)) 
        return 1; 
  
    /* If we reach here then  
    tree is not height-balanced */
    return 0; 
}
