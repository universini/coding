#!/usr/bin/python

class Node(object):

    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

def insert(root, node):
    if root is None:
        root = node
    else:
        try:
            if node.data <= root.data:
               if root.left == None:
                   root.left = node
               else:
                   insert(root.left, node)
            else:
               if root.right is None:
                   root.right = node
               else:
                   insert(root.right, node)
        except:
            print("Root is not initialized")

def inorder(root):
    if not root:
        return

    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)

def min(root):
	if root  is None:
		return root
	return(min(root.right))

def delete(root, node):
	if not root:
		return

	if node.data < root.data:
		root.left = delete(root.left, node)
	elif node.data > root.data:
		root.right = delete(root.right, node)
	else:
		if root.right is None or root.left is None:
			'''case1: no children'''
			root = None
		elif root.left is None:
			'''case2: left child'''
			temp = root
			root = root.right
			temp = None
		elif root.right is None:
			'''case2: right child'''
			temp = root
			root = root.left
			temp = None
		else:
			'''case4: both children'''
			temp = min(root.right)
			root.data = temp.data
			root.right = delete(root.right, temp)
	
if __name__ == '__main__':

    root = Node(7)
    insert(root, Node(3))
    insert(root, Node(2))
    insert(root, Node(5))
    insert(root, Node(8))
    insert(root, Node(1))
    insert(root, Node(9))
    insert(root, Node(4))
    insert(root, Node(6))

    inorder(root)
    print("\n")
    delete(root, Node(8))
    inorder(root)
    print("\n")
