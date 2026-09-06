# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import Optional

class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
      
        This function recovers a BST where exactly two nodes have been swapped.
        Uses Morris Traversal concept with in-order traversal to find the two swapped nodes.
        """
      
        def inorder_traversal(node: Optional[TreeNode]) -> None:
            """
            Perform in-order traversal to find two swapped nodes in BST.
          
            In a valid BST's in-order traversal, values should be in ascending order.
            We look for violations of this property to identify swapped nodes.
            """
            if node is None:
                return
          
            nonlocal previous_node, first_swapped, second_swapped
          
            # Traverse left subtree
            inorder_traversal(node.left)
          
            # Process current node
            # Check if current node violates BST property (previous > current)
            if previous_node and previous_node.val > node.val:
                if first_swapped is None:
                    # First violation found: mark the previous node as first swapped
                    first_swapped = previous_node
                # Always update second swapped to current node
                # This handles both adjacent and non-adjacent swaps
                second_swapped = node
          
            # Update previous node for next comparison
            previous_node = node
          
            # Traverse right subtree
            inorder_traversal(node.right)
      
        # Initialize tracking variables
        previous_node = None      # Tracks the previous node in in-order traversal
        first_swapped = None      # First node that violates BST property
        second_swapped = None     # Second node that violates BST property
      
        # Find the two swapped nodes
        inorder_traversal(root)
      
        # Swap the values of the two identified nodes to recover the BST
        first_swapped.val, second_swapped.val = second_swapped.val, first_swapped.val
