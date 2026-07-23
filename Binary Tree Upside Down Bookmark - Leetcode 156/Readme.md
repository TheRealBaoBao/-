You are given a binary tree and need to transform it by flipping it upside down according to specific rules.

The transformation works as follows:

The leftmost node (original left child) becomes the new root of the tree
The original root node becomes the right child of what was previously its left child
The original right child becomes the left child of what was previously the root's left child
This transformation is applied recursively throughout the tree, level by level, starting from the bottom.

For example, if you have a tree structure like:

    1
   / \
  2   3
 / \
4   5
After the transformation, it becomes:

    4
   / \
  5   2
     / \
    3   1
The problem guarantees that:

Every right node has a sibling (a left node that shares the same parent)
No right node has any children of its own
The task is to implement a function that takes the root of the original binary tree and returns the root of the new upside-down tree. If the tree is empty or has no left child, it remains unchanged.

The recursive solution works by:

First recursively flipping the left subtree to find the new root
Then rearranging the pointers: making the current root the right child of its original left child, and the original right child becomes the left child of the original left child
Setting the current node's left and right pointers to None to avoid cycles
Returning the new root found from the leftmost path
