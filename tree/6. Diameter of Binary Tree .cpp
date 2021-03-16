/*
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. The diagram below shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).

Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4

You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
*/
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
int max(int a, int b) { return (a > b) ? a : b; }
int height(struct Node* node)
{
    // base case tree is empty
    if (node == NULL)
        return 0;
 
    // If tree is not empty then height = 1 + max of left
    // height and right heights
    return 1 + max(height(node->left), height(node->right));
}
 
/* Computes the diameter of binary tree with given root.  */
class Solution
{
    public:
    int diameter(Node* root) {
    // Your code here
    // base case where tree is empty
    if (root == NULL)
        return 0;
 
    // get the height of left and right sub-trees
    int lheight = height(root->left);
    int rheight = height(root->right);
 
    // get the diameter of left and right sub-trees
    int ldiameter = diameter(root->left);
    int rdiameter = diameter(root->right);
 
    // Return max of following three
    // 1) Diameter of left subtree
    // 2) Diameter of right subtree
    // 3) Height of left subtree + height of right subtree + 1
    return max(lheight + rheight + 1,
            max(ldiameter, rdiameter));
    }

};