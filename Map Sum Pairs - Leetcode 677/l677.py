from typing import List, Optional
from collections import defaultdict


class Trie:
    """A Trie (prefix tree) data structure for efficient prefix-based operations."""
  
    def __init__(self):
        # Array to store 26 child nodes (one for each lowercase letter a-z)
        self.children: List[Optional['Trie']] = [None] * 26
        # Accumulated value at this node (sum of all values for words ending here or passing through)
        self.val: int = 0

    def insert(self, word: str, delta: int) -> None:
        """
        Insert a word into the trie and update values along the path.
      
        Args:
            word: The word to insert
            delta: The value difference to add to each node along the path
        """
        node = self
        for char in word:
            # Convert character to index (0-25)
            index = ord(char) - ord('a')
            # Create new node if path doesn't exist
            if node.children[index] is None:
                node.children[index] = Trie()
            # Move to child node
            node = node.children[index]
            # Update the accumulated value at this node
            node.val += delta

    def search(self, prefix: str) -> int:
        """
        Search for a prefix and return the sum of all values with this prefix.
      
        Args:
            prefix: The prefix to search for
          
        Returns:
            The sum of all values for words with the given prefix, or 0 if prefix doesn't exist
        """
        node = self
        for char in prefix:
            # Convert character to index (0-25)
            index = ord(char) - ord('a')
            # If path doesn't exist, prefix is not in trie
            if node.children[index] is None:
                return 0
            # Move to child node
            node = node.children[index]
        # Return the accumulated value at the prefix node
        return node.val


class MapSum:
    """
    A data structure that maps strings to values and supports sum queries for prefixes.
    If a key already exists, its value is overridden.
    """
  
    def __init__(self):
        # Dictionary to store current value for each key
        self.key_value_map = defaultdict(int)
        # Trie to efficiently compute prefix sums
        self.trie = Trie()

    def insert(self, key: str, val: int) -> None:
        """
        Insert or update a key-value pair.
      
        Args:
            key: The string key to insert or update
            val: The new value for the key
        """
        # Calculate the difference between new value and old value (0 if new key)
        delta = val - self.key_value_map[key]
        # Update the stored value for this key
        self.key_value_map[key] = val
        # Update the trie with the value difference
        self.trie.insert(key, delta)

    def sum(self, prefix: str) -> int:
        """
        Return the sum of all values for keys that start with the given prefix.
      
        Args:
            prefix: The prefix to search for
          
        Returns:
            The sum of values for all keys with the given prefix
        """
        return self.trie.search(prefix)


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
