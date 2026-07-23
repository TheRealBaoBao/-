class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def upside_down_binary_tree(root: Node) -> Node:
    # WRITE YOUR BRILLIANT CODE HERE
    return None

# this function builds a tree from input; you don't have to modify it
# learn more about how trees are encoded in https://algo.monster/problems/serializing_tree
def build_tree(nodes, f):
    val = next(nodes)
    if val == "x":
        return None
    left = build_tree(nodes, f)
    right = build_tree(nodes, f)
    return Node(f(val), left, right)

def format_tree(node):
    if node is None:
        yield "x"
        return
    yield str(node.val)
    yield from format_tree(node.left)
    yield from format_tree(node.right)

if __name__ == "__main__":
    root = build_tree(iter(input().split()), int)
    res = upside_down_binary_tree(root)
    print(" ".join(format_tree(res)))
