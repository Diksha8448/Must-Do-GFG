/*
Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.

Example 1:

Input:
         5
       /   \
      1     1
     /       \
    2         2
Output: True
Explanation: Tree is mirror image of
itself i.e. tree is symmetric

You don't need to read input or print anything. Your task is to complete the function isMirror() which takes the root of the Binary Tree as its input and returns True if the given Binary Tree is a same as the Mirror image of itself. Else, it returns False.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).
*/
/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
bool isMirror(struct Node* root1, struct Node* root2)
{
    // If both trees are emptu, 
    // then they are mirror images
    if (root1 == NULL && root2 == NULL)
        return true;
 
    
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right)
               && isMirror(root1->right, root2->left);
 
    // if none of above conditions is true then root1
    // and root2 are not mirror images
    return false;
}
// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
	// Code here
	return isMirror(root, root);
	
}